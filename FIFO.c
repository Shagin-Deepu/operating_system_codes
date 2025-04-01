
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n,f,c,d=0,i,j;
	int page[25], replace[6];
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
		replace[i]=-1;
	}
	replace[f+1]=0;
	printf("FIFO page replacement process:\n");
	c=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<f;j++)
        	{
       		if(page[i]==replace[j])
            		{
				replace[f+1]=1;
				break;
			}
			replace[f+1]=0;
		}
		if(replace[f+1]!=1)
		{
			replace[c]=page[i];
	 		c=(c+1)%f;
	 	}
		for(int k=0;k<f;k++)
		{
			if(replace[k]>=0)
			{
				printf("%d ",replace[k]);
			}
			else
			{
				printf("- ");
			}
		}
		if(replace[f+1]==1)
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
