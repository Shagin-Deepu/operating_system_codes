#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
void main()
{
	int pid=fork ();
	if(pid==0)
	{
		printf("i am child");
	}
	else if (pid>0)
	{
		printf("i am parent");
		wait(NULL);
		printf("parentwaited for child");
	}
	else
	{
	printf("child process creation failed");
	}
}	
