#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
struct dirent *dptr;
int main(int arge, char *arge2[])
{
	char buff[100];
	DIR *dirp ;
	printf("enter the directory name");
	scanf("%s",buff);
	if ((dirp= opendir (buff))= NULL)
	{
		printf("the given directory doesn't exist");
		exit(1);
	}
	while (dptr = readdir (dirp))
	{
		printf("%s/n", dptr -> d_name);
	}
	closedir(dirp);
}

