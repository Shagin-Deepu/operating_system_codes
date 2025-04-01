#include<stdio.h>
int main()
{
	int bt[10],at[10],p[10],wt[10],tat[10],ct[10],i,j,k,n,sum;
	float total_tat=0,total_wt=0;
	printf("Enter number of processes : ");
	scanf("%d",&n);
	printf("Enter the Burst Time and Arrival Time\n");
	for(i=0;i<n;i++)
	{
		printf("Enter Arrival Time of process %d : ",i+1);
		scanf("%d",&at[i]);	
		printf("Enter Burst Time of process %d : ",i+1);
		scanf("%d",&bt[i]);
	}
	
	sum=at[0];
	for(j=0;j<n;j++)
	{
		sum=sum+bt[j];
		ct[j]=sum;
	}
	
	for(k=0;k<n;k++)
	{
		tat[k]=ct[k]-at[k];
		total_tat=total_tat+tat[k];
	}
	
	for(k=0;k<n;k++)
	{
		wt[k]=tat[k]-bt[k];
		total_wt=total_wt+wt[k];
	}
	
	printf("\nPROCESS\tAT\tBT\tCT\tTAT\tWT\n\n");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("Average Turn Around Time : %f\n",(total_tat/n));
	printf("Average Waiting Time : %f\n",(total_wt/n));
	return 0;
}
