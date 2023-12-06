#include <stdio.h>

int main() {
    int i, limit, total = 0, x, counter = 0, time_quantum;
    int wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;

    printf("Enter total no of processes: ");
    scanf("%d", &limit);
    x = limit;

    for (i = 0; i < limit; i++) {
        printf("Enter the details of process[%d]:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    printf("\tProcess ID\tBurst Time\tTurn Around time\tWaiting Time\n");

    for (total = 0; x != 0;) {
        if (temp[i] <= time_quantum && temp[i] > 0) {
            total = total + temp[i];
            temp[i] = 0;
            counter = 1;
        } else if (temp[i] > 0) {
            temp[i] = temp[i] - time_quantum;
            total = total + time_quantum;
        }

        if (temp[i] == 0 && counter == 1) {
            x--;
            printf("Process[%d]\t\t%d\t\t%d\t\t%d\n", i + 1, total - at[i], total - at[i] - bt[i], total - at[i]);
            wt = wt + total - at[i] - bt[i];
            tat = tat + total - at[i];
            counter = 0;
        }

        if (i == limit - 1)
            i = 0;
        else if (at[i + 1] <= total)
            i++;
        else
            i = 0;
    }

    avg_wt = (float)wt / limit;
    avg_tat = (float)tat / limit;

    printf("\nAverage waiting time: %f", avg_wt);
    printf("\nAverage turn around time: %f", avg_tat);

    return 0;
}

