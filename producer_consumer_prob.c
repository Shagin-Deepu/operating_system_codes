#include<stdio.h>
#include<stdlib.h>
int mutex =1;

int full= 0;
int empty,x=0;

void producer ()
{
	--mutex;
	++full;
	--empty;
	x++;
	printf("\n producer produces item %d",x );
	++mutex;
}

void consumer()
{
	--mutex;
	--full;
	++empty;
	printf("\n consumer consumes item %d",x);
	x--;
	++mutex;
}

int main ()
{
	int n,i;
	printf("\n 1.Enter 1 for Producer");
	printf("\n 1.Enter 2 for Consumer");
	printf("\n 1.Enter 3 for Exit");
	printf("\n 	Enter buffer size");
	scanf ("%d",&empty);
	for (i=1; i>0; i++)
	{
		printf("\n Enter your choice");
		scanf("%d",&n);
		switch(n)
		{
		case 1: if ((mutex==1)&&(empty!=0))
			{
				producer();
			}
			else
			{
				printf ("buffer is FULL");
			}	break;
		case 2 : if ((mutex==1)&&(full!=0))
			{
				consumer();
			}
			else 
			{
				printf ("buffer is empty");
			}
		case 3 : exit (0);
			break ;
		}
	}
}

