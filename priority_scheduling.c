#include<stdio.h>
int main()
{
	int at[10],bt[10],ct[10],tat[10],wt[10],i,j,n,prio[10],temp,p[10],sum=0,k;
	float total_tat=0,total_wt=0;
	printf("Enter number of process : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter priority of P%d : ",i+1);
		scanf("%d",&prio[i]);
		printf("Enter Arrival Time of process %d : ",i+1);
		scanf("%d",&at[i]);
		printf("Enter Burst Time of process %d : ",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n-i-1;j++)
		{
			if(prio[j]>prio[j+1])
			{
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
		
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
	
				temp=at[j];
				at[j]=at[j+1];
				at[j+1]=temp;
			}
		}	
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

	printf("\nPROCESS\tPRIORITY\tAT\tBT\tCT\tTAT\tWT\n\n");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,prio[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("Average Turn Around Time : %f\n",(total_tat/n));
	printf("Average Waiting Time : %f\n",(total_wt/n));
	return 0;
}
