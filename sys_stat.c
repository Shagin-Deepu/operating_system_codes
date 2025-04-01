#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
void main()
{
	char path[10];
	struct stat*buf;
	buf=(struct stat*)malloc(sizeof(struct stat));
	printf("enterthe path of file ");
	scanf ("%s",path);
	stat (path, buf);
	printf("user id :%d\n",buf->st_uid);
	printf("block size :%d\n",buf->st_blksize);
	printf("time :%d\n",buf->st_atime);
	printf("permission :%d\n",buf->st_mode);
	printf("no of links :%d\n",buf->st_nlink);
}
