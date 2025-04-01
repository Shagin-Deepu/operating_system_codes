
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n,f,c,d=0,i,j,max=0,maxf,b;
	int page[25], replace[6][2];
	printf("enter the length of page string:");
	scanf("%d",&n);
	printf("enter the frame:");
	scanf("%d",&f);
	printf("enter the page string:");
	for(i=0;i<n;i++)
	{
		scanf(" %d",&page[i]);
	}
	for(i=0;i<f;i++)
	{
	replace[i][1]=-1;
	replace[i][0]=f;
	}
	replace[f+1][1]=0;
	printf("LRU page replacement process:\n");
	c=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<f;j++)
		{
			if(page[i]==replace[j][1])
			{
				replace[f+1][1]=1;
				break;
			}
			replace[f+1][1]=0;
		}
		if(c>f)
		{
			if(replace[f+1][1]!=1)
			{
				for(int m=0;m<f;m++)
				{
					if(replace[m][0]>max)
					{
                      				max=replace[m][0];
						maxf=m;
					}
				}
				replace[maxf][1]=page[i];
				max=0;
				for(int p=0;p<f;p++)
				{
				replace[p][0]+=1;
				}
			}
			else
			{
				replace[j][0]=0;
				for(int p=0;p<f;p++)
				{
					replace[p][0]+=1;
				}
			}
		}
        	else
        	{
			if(replace[f+1][1]!=1)
			{
				replace[c][1]=page[i];
				replace[c][0]=0;c++;
				for(b=0;b<=c;b++)
				{
					replace[b][0]+=1;
				}
			}
			else
			{
				replace[j][0]=0;
				for(b=0;b<=c;b++)
				{
					replace[b][0]+=1;
				}
			}
		}
		for(int k=0;k<f;k++)
		{
			if(replace[k][1]>=0)
			{
				printf("%d\t",replace[k][1]);
			}
			else
			{
				printf("-\t");
			}
		}
		if(replace[f+1][1]==1)
		{
			printf("H\n");
			d++;
		}
		else
		{
			printf("M\n");
		}
	}
	printf("HIT :%d/%d\n",d,n);
	printf("MISS :%d/%d",n-d,n);
	
}
