#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
void main()
{
	int pid=fork();
	if(pid==0)
	{
		printf("i am child");
		printf("child id :%d\n",getpid ());
	}
	else if (pid>0)
	{
		printf("i am parent");
		printf("parent id :%d\n",getpid ());
	}
	else
	{
	printf("child process creation failed");
	}
}	
