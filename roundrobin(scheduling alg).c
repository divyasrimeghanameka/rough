#include <stdio.h>
int main() {
    int i, j, n, bt[20], wt[20], tat[20], t, ct[20], max;
    float wtavg = 0, ttavg = 0, temp = 0;
    printf("\nEnter number of processes:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter burst time for process %d: ", i + 1);
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
                if (bt[i] < t) 
                {
                    tat[i] = temp + bt[i]; 
                    temp += bt[i];
                    bt[i] = 0; 
                } 
                else 
                {
                    bt[i] -= t; 
                    temp += t;
                }
            }
        }
    }
    for (i = 0; i < n; i++) 
    {
        wt[i] = tat[i] - ct[i]; 
        ttavg += tat[i];
        wtavg += wt[i];
    }
    printf("\nAverage Turnaround Time: %.2f", ttavg / n);
    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\n\tProcess\tBurst time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++) 
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n", i + 1, ct[i], wt[i], tat[i]);
}
