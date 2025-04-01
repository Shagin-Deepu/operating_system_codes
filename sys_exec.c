#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
void main()
{
	int pid= fork ();
	if (pid ==0)
	{	
		char*args[]= { "/EXEC", NULL};
		printf("to child file\n");
		execv(args[0],args);
	}
	else if (pid >0)
	{
		wait(NULL);
		printf("back to parent file");
	}
}
