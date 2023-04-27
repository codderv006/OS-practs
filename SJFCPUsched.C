// #include <stdio.h>
// int main()
// {
// 	// Matrix for storing Process Id, Burst Time, Average Waiting Time & Average Turn Around Time.
// 	int A[100][4];
// 	int i, j, n, total = 0, index, temp;
// 	float avg_wt, avg_tat;
// 	printf("Enter number of process: ");
// 	scanf("%d", &n);
// 	printf("Enter Burst Time:\n");
// 	// User Input Burst Time and alloting Process Id.
// 	for (i = 0; i < n; i++) {
// 		printf("P%d: ", i + 1);
// 		scanf("%d", &A[i][1]);
// 		A[i][0] = i + 1;
// 	}
// 	// Sorting process according to their Burst Time.
// 	for (i = 0; i < n; i++) {
// 		index = i;
// 		for (j = i + 1; j < n; j++)
// 			if (A[j][1] < A[index][1])
// 				index = j;
// 		temp = A[i][1];
// 		A[i][1] = A[index][1];
// 		A[index][1] = temp;

// 		temp = A[i][0];
// 		A[i][0] = A[index][0];
// 		A[index][0] = temp;
// 	}
// 	A[0][2] = 0;
// 	// Calculation of Waiting Times
// 	for (i = 1; i < n; i++) {
// 		A[i][2] = 0;
// 		for (j = 0; j < i; j++)
// 			A[i][2] += A[j][1];
// 		total += A[i][2];
// 	}
// 	avg_wt = (float)total / n;
// 	total = 0;
// 	printf("P	 BT	 WT	 TAT\n");
// 	// Calculation of Turn Around Time and printing the
// 	// data.
// 	for (i = 0; i < n; i++) {
// 		A[i][3] = A[i][1] + A[i][2];
// 		total += A[i][3];
// 		printf("P%d	 %d	 %d	 %d\n", A[i][0],
// 			A[i][1], A[i][2], A[i][3]);
// 	}
// 	avg_tat = (float)total / n;
// 	printf("Average Waiting Time= %f", avg_wt);
// 	printf("\nAverage Turnaround Time= %f", avg_tat);
// }


#include<stdio.h>
 int main()
{
    int burst_time[20],p[20],waiting_time[20],tat[20],i,j,n,total=0,
pos,temp;
    float avg_waiting_time,avg_tat;
    printf("please enter number of process: ");
    scanf("%d",&n);
    printf("\n enter the Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&burst_time[i]);
        p[i]=i+1;         
    }
   // from here, burst times sorted
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    waiting_time[0]=0;            
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
        total+=waiting_time[i];
    }
    avg_waiting_time=(float)total/n;      
    total=0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=burst_time[i]+waiting_time[i];   
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],burst_time[i],waiting_time[i],tat[i]);
    }
    avg_tat=(float)total/n;    
    printf("\n\n the average Waiting Time=%f",avg_waiting_time);
    printf("\n  the average Turnaround Time=%f\n",avg_tat);
}
