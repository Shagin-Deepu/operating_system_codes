#include<stdio.h>
int main()
{
	int n;	
	int bt[20], at[20], wt[20], tat[20], ct[10];
	int sum, i, j, k;
	float totaltat= 0,totalwt = 0;
	printf("enter the total mo of process");
	scanf("%d", &n);
	printf("\n enter the process arrival time &burst time );
	for(i=0,i<n,++)
	{
		printf("enter arrival time of process [%d]",i+1);
		scanf("%d",&at[i]);
		printf("enter burst time of process [%d]",i+1);
		scanf("%d",&bt[i]);
	}
	sum= at[0];
	for(j=0;j<n;j++)
	{
		sum=sum+bt[j];
	}
	ct[j]=sum;
	for (k=0;k<n;k++)
	{	
		tat[k]=ct[k]-at[k];
		totaltat= totaltat + tat[k];
	}
	for(k=0;k<n;k++);
	{	
		wt[k]=tat[k]-bt[k];
		totalwt=totalwt+wt[k];
	}
	printf("\n process \t at \t bt \t tat
	
