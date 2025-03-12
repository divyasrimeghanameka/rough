#include<stdio.h>
int main()
{
	int p[20],bt[20],pri[20],wt[30],tat[20],i,k,n,temp;
	float wtavg,tatavg;
	printf("\nEnter number of processes:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i;
		printf("enter burst time & priority of process %d ",i);
		scanf("%d %d",&bt[i],&pri[i]);
	}
	for(i=0;i<n-1;i++)
		for(k=i+1;k<n;k++)
			if(pri[i]>pri[k])
			{
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
				temp=pri[i];
				pri[i]=pri[k];
				pri[k]=temp;
			}
	wtavg=wt[0]=0;
	tatavg=tat[0]=bt[0];
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=tat[i-1]+bt[i];
		wtavg=wtavg+wt[i];
		tatavg=tatavg+tat[i];
	}
	printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
	for(i=0;i<n;i++)
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i],pri[i],bt[i],wt[i],tat[i]);
	printf("\nAverage waiting time is %f:",wtavg/n);
	printf("\naverage turn around time is %f:",tatavg/n);
}
output:
Enter number of processes:
3
enter burst time & priority of process 0 4
5
enter burst time & priority of process 1 6
7
enter burst time & priority of process 2 8
9

PROCESS		PRIORITY	BURST TIME	WAITING TIME	TURNAROUND TIME
0		5		4		0		4
1		7		6		4		10
2		9		8		10		18
Average waiting time is 4.666667:
average turn around time is 10.666667
