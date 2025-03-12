#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#define MAX_OPEN_PORTS 5
int openPorts=0;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t portsAvailable=PTHREAD_COND_INITIALIZER;
void* requestPort(void* thread_id)
{
	int id=*((int *)thread_id);
	pthread_mutex_lock(&mutex);
	while(openPorts >= MAX_OPEN_PORTS)
	{
		printf("Thread %d: Waiting for a port to become available...\n",id);
		pthread_cond_wait(&portsAvailable,&mutex);
	}
	openPorts++;
	printf("Thread %d: opened a port. Total open ports: %d\n",id,openPorts);
	pthread_mutex_unlock(&mutex);
	sleep(2);
	pthread_mutex_lock(&mutex);
	openPorts--;
	printf("Thread %d: Released a port. Total open ports: %d\n",id,openPorts);
	pthread_cond_signal(&portsAvailable);
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}
int main()
{
	const int NUM_THREADS=10;
	pthread_t threads[NUM_THREADS];
	int thread_ids[NUM_THREADS];
	for(int i=0;i<NUM_THREADS;i++)
	{
		thread_ids[i]=i+1;
		if(pthread_create(&threads[i],NULL,requestPort,(void*)&thread_ids[i])!=0)
		{
			perror("Failed to createthread");
			exit(1);
		}
	}
	for(int i=0;i<NUM_THREADS;i++)
	{
		pthread_join(threads[i],NULL);
	}
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&portsAvailable);
	printf("All threads have completed.\n");
	return 0;
}
 output:
 Thread 1: opened a port. Total open ports: 1
Thread 4: opened a port. Total open ports: 2
Thread 5: opened a port. Total open ports: 3
Thread 3: opened a port. Total open ports: 4
Thread 2: opened a port. Total open ports: 5
Thread 7: Waiting for a port to become available...
Thread 9: Waiting for a port to become available...
Thread 10: Waiting for a port to become available...
Thread 6: Waiting for a port to become available...
Thread 8: Waiting for a port to become available...
Thread 1: Released a port. Total open ports: 4
Thread 5: Released a port. Total open ports: 3
Thread 2: Released a port. Total open ports: 2
Thread 4: Released a port. Total open ports: 1
Thread 3: Released a port. Total open ports: 0
Thread 8: opened a port. Total open ports: 1
Thread 9: opened a port. Total open ports: 2
Thread 6: opened a port. Total open ports: 3
Thread 10: opened a port. Total open ports: 4
Thread 7: opened a port. Total open ports: 5
Thread 9: Released a port. Total open ports: 4
Thread 8: Released a port. Total open ports: 3
Thread 6: Released a port. Total open ports: 2
Thread 7: Released a port. Total open ports: 1
Thread 10: Released a port. Total open ports: 0
All threads have completed.
