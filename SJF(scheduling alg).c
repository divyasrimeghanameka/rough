#include<stdio.h>
int main()
{
	int p[20],bt[20],wt[20],tat[20],i,k,n,temp;
	float wtavg,tatavg;
	printf("\nenter number of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i;
		printf("\nenter burst time for process %d:",i);
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n;i++)
		for(k=i+1;k<n;k++)
			if(bt[i]>bt[k])
			{
				temp=bt[i];
				bt[i]=bt[k];
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
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
			printf("\n\t Process \t Burst Time \t Waiting Time \t Turnaround Time\n");
			for(i=0;i<n;i++)
				printf("\n\t P%d \t\t %d \t\t %d \t\t %d",p[i],bt[i],wt[i],tat[i]);
			printf("\n Average Waiting Time:%f\n",wtavg/n);
			printf("\n AVerage TurnAround Time:%f\n",tatavg/n);
}
output:
enter number of processes:4

enter burst time for process 0:6

enter burst time for process 1:8

enter burst time for process 2:7

enter burst time for process 3:3

	 Process 	 Burst Time 	 Waiting Time 	 Turnaround Time

	 P3 		 3 		 0 		 3
	 P0 		 3 		 3 		 6
	 P2 		 3 		 6 		 9
	 P1 		 3 		 9 		 12
 Average Waiting Time:4.500000

 AVerage TurnAround Time:7.500000
