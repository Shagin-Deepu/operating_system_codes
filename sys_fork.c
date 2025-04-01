//inter proccess communication -- IPC
#include<unistd.h>
#include<stdio.h>
void main()
{
	int pid = fork ();
	if(pid ==0)
	{
		printf("I am a child \n");
	}
	else if (pid >0)
	{
		printf("I am a parent\n");
	}
	else 
	{
		printf ("child proccess creation failed\n");
	}
}	


