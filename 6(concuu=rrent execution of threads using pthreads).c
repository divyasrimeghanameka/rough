#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *Mythread1(void *vargp)
{
	int i;
	printf("thread1\n");
	for(i=0;i<=10;i++)
		printf("i=%d\n",i);
	printf("exit from thread1\n");
	return NULL;
}
void *Mythread2(void *vargp)
{
	int j;
	printf("thread2\n");
	for(j=0;j<=10;j++)
		printf("j=%d\n",j);
	printf("exit from thread2\n");
	return NULL;
}
int main()
{
	pthread_t tid1,tid2;
	printf("before thread\n");
	pthread_create(&tid1,NULL,Mythread1,NULL);
	pthread_create(&tid2,NULL,Mythread2,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	exit(0);
}
output:
before thread
thread1
i=0
i=1
i=2
i=3
i=4
i=5
i=6
i=7
i=8
i=9
i=10
exit from thread1
thread2
j=0
j=1
j=2
j=3
j=4
j=5
j=6
j=7
j=8
j=9
j=10
exit from thread2
