#include <stdio.h>
int process_list[10][6],execution_list[10][6];
int main()
{
	int n,i,time=0,temp,total_tat=0,total_wt=0,j,tq,total_burst=0,k;
	printf("enter the number of process: ");
	scanf("%d",&n);
	printf("enter the TQ: ");
	scanf("%d",&tq);
	for(i=0;i<n;i++)
	{
		process_list[i][0]=i+1;
		printf("enter the arrival time of P%d:",i+1);
		scanf("%d",&process_list[i][1]);
		printf("enter the burst time of P%d :",i+1);
		scanf("%d",&process_list[i][2]);
		total_burst=total_burst+process_list[i][2];
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(process_list[j][1]>process_list[j+1][1])
			{
				for(k=0;k<3;k++)
				{
					temp = process_list[j][k];
					process_list[j][k]=process_list[j+1][k];
					process_list[j+1][k]=temp;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			execution_list[i][j]=process_list[i][j];
		}
	}
	while(total_burst>0)
	{
		for(i=0;i<n;i++)
		{
			if(execution_list[i][1]<=time && execution_list[i][2]>0)
			{
				if(execution_list[i][2]>=tq)
				{
					time=time+tq;
					execution_list[i][3]=time;
					execution_list[i][2]=execution_list[i][2]-tq;
					total_burst=total_burst-tq;
					for(j=i;j<n-1;j++)
					{
						if(execution_list[j+1][1]<=time)
						{
							for(k=0;k<4;k++)
							{
								temp = execution_list[j][k];
								execution_list[j][k]=execution_list[j+1][k];
								execution_list[j+1][k]=temp;
							}
						}
					}
					break;
				}
				else
				{
					time=time+execution_list[i][2];
					execution_list[i][3]=time;
					total_burst=total_burst-execution_list[i][2];
					execution_list[i][2]=0;
					break;
				}
				if(i==n && total_burst>0)
				{
					time=time+1;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(process_list[i][0]==execution_list[j][0])
			{
				process_list[i][3]=execution_list[j][3];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		process_list[i][4]=process_list[i][3]-process_list[i][1];
		total_tat=total_tat+process_list[i][4];
		process_list[i][5]=process_list[i][4]-process_list[i][2];
		total_wt=total_wt+process_list[i][5];
	}
	printf("\nprocess  at\tbt\tct\ttat\twt\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(process_list[j][0]==i+1)
			{
				printf("P%d\t%d\t%d\t%d\t%d\t%d\n",process_list[j][0],process_list[j][1],process_list[j][2],process_list[j][3],process_list[j][4],process_list[j][5]);
				break;
			}
		}
	}
	printf("\navg tat: %fms\n",(float)total_tat/n);
	printf("avg wt:%fms",(float)total_wt/n);
	return 0;
}
