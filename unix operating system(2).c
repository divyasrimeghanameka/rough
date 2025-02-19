program 1:
#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
struct dirent*dptr;
int main(int argc,char*argv[])
{
	char buff[100];
	DIR*dirp;
	struct dirent *dptr;
	printf("\n\nENTER DIRECTORY NAME");
	scanf("%s",buff);
	dirp=opendir(buff);
	if(dirp==NULL)
	{
		printf("the given directory does not exist");
		exit(1);
	}
	printf("contents of directory are:\n");
	while((dptr=readdir(dirp))!=NULL)
	{
		printf("%s\n",dptr->d_name);
	}
	closedir(dirp);
}
output:
ENTER DIRECTORY NAMEdivya
contents of directory are:
sowmya.txt
..
.
program2:
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int pid,pid1,pid2;
	pid=fork();
	if(pid==-1)
	{
		printf("ERROR IN PROCESS CREATION\n");
		exit(1);
	}
	if(pid!=0)
	{
		pid1=getpid();
		printf("\nthe parent proces ID is %d\n",pid1);
	}
	else
	{
		pid2=getpid();
		printf("\nsecond process ID is %d\n",pid2);
	}
}		
output:
the parent proces ID is 6000

second process ID is 6001
