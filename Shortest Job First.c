#include<stdio.h>

main()
{
	int p[20],bt[20],wt[20],tat[20],n,i,k,temp;
	float wtavg,tatavg;
	
	printf("Enter number of processes -- ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i;
		printf("Enter Burst time for process %d --",i);
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n;i++)
	for(k=i+1;i<n;i++)
	if(bt[i]>bt[k])
		temp=bt[i];
		bt[i]=bt[k];
		bt[k]=temp;
		
		temp=p[i];
		p[i]=p[k];
		p[k]=temp;
	wt[0]=wtavg=0;
	tat[0]=tatavg=bt[0];
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=tat[i-1]+bt[i];
		wtavg=wtavg+wt[i];
		tatavg=tatavg+tat[i];
	}
	printf("\n\tProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time\n");
	for(i=0;i<n;i++)
	
	printf("\n\tP%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
	printf("Average Waiting Time is %f",wtavg/n);
	printf("Average Turnaround time is %f",tatavg/n);
	
	
	
}
