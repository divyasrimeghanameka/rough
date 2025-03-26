#include <stdio.h>
int main() 
{
    int i, j, n, bt[20], wt[20], tat[20], t, ct[20], max;
    float wtavg = 0, tatavg = 0, temp = 0;
    printf("\nEnter number of processes:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        printf("\nEnter burst time for process P%d: ", i + 1);
        scanf("%d", &bt[i]);
        ct[i] = bt[i]; 
    }
    printf("\nEnter the size of time slice: ");
    scanf("%d", &t);
    max = bt[0];
    for (i = 1; i < n; i++)  
    {
        if (max < bt[i])
            max = bt[i];
    }
    for (j = 0; j <= (max / t); j++) 
    {
        for (i = 0; i < n; i++) 
        {
            if (bt[i] != 0) 
            {
                if (bt[i] <= t) 
                {
                    tat[i] = temp + bt[i]; 
                    temp = temp + bt[i];
                    bt[i] = 0; 
                } 
                else 
                {
                    bt[i] = bt[i] - t; 
                    temp = temp + t;
                }
            }
        }
    }
    for (i = 0; i < n; i++) 
    {
        wt[i] = tat[i] - ct[i]; 
        tatavg += tat[i];
        wtavg += wt[i];
    }
    printf("\nAverage Turnaround Time: %.2f", tatavg / n);
    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\n\tProcess\tBurst time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++) 
        printf("\tP%d\t\t\t%d\t\t\t\t%d\t\t\t\t\t%d\n", i + 1, ct[i], wt[i], tat[i]);
}
/*output:
Enter number of processes:
3

Enter burst time for process 1: 24

Enter burst time for process 2: 3

Enter burst time for process 3: 3

Enter the size of time slice: 3

Average Turnaround Time: 15.00
Average Waiting Time: 5.00
	Process	Burst time	Waiting time	Turnaround time
	P1			24				6					30
	P2			3				3					6
	P3			3				6					9*/
