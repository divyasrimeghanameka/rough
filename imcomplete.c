#include<stdio.h>
int main()
{
	int p[20],bt[20],pri[20,wt[30],tat[20],i,k,n,temp;
	float wtavg,tatavg;
	printf("\nEnter number of processes:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i;
		printf("enter burst time & priority of process %d ",i);
		scanf("%d %d",&bt[i],&pri[i]);
	}
	for(i=0;i<n;i++)
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
		tat[i]=tat[i-1]
