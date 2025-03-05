#include<stdio.h>
int main()
{
	int bt[20],wt[20],tat[20],i,n;
	float wtavg,tatavg;
	printf("\nenter the number of processes .. ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nenter burst time for process %d--",i);
		scanf("%d",&bt[i]);
	}
	wt[0]=wtavg=0;
	tat[0]=tatavg=bt[0];
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=tat[i-1]+bt[i];
		wtavg=wtavg+wt[i];
		tatavg=tatavg+tat[i];
	}
	printf("\t Process \t Burst time \t Waiting time \t TurnAround time \n");
	for(i=0;i<n;i++)
		printf("\n\t %d \t\t %d \t\t %d \t\t %d ",i,bt[i],wt[i],tat[i]);
	printf("\navg waiting time:%f",wtavg/n);
	printf("\navg turnaround time:%f",tatavg/n);
	return 0;
} 
output:
enter the number of processes .. 3

enter burst time for process 0--24

enter burst time for process 1--3

enter burst time for process 2--3
	 Process 	 Burst time 	 Waiting time 	 TurnAround time 

	 0 		 24 		 0 		 24 
	 1 		 3 		 24 		 27 
	 2 		 3 		 27 		 30 
avg waiting time:17.000000
avg turnaround time:27.000000
