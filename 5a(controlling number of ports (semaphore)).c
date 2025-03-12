#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#define MAX_PORTS 5
sem_t port_semaphore;
void* open_port(void* port)
{
	int port_number=*((int* )port);
	printf("Attempting to open port %d\n",port_number);
	sem_wait(&port_semaphore);
	printf("Port %d is opened\n",port_number);
	sleep(2);
	sem_post(&port_semaphore);
	printf("Port %d is closed\n",port_number);
	pthread_exit(NULL);
}
int main()
{
	pthread_t threads[MAX_PORTS];
	int port_numbers[MAX_PORTS];
	sem_init(&port_semaphore,0,MAX_PORTS);
	for(int i=0;i<MAX_PORTS;i++)
	{
		port_numbers[i]=i+1;
		if(pthread_create(&threads[i],NULL,open_port,&port_numbers[i])!=0)
		{
			perror("Failed to create thread");
			exit(1);
		}
	}
	for(int i=0;i<MAX_PORTS;i++)
	{
		pthread_join(threads[i],NULL);
	}
	sem_destroy(&port_semaphore);
	return 0;
}
output:
Attempting to open port 1
Port 1 is opened
Attempting to open port 2
Attempting to open port 5
Port 5 is opened
Port 2 is opened
Attempting to open port 3
Port 3 is opened
Attempting to open port 4
Port 4 is opened
Port 3 is closed
Port 2 is closed
Port 1 is closed
Port 4 is closed
Port 5 is closed
