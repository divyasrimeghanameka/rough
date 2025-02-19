#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1024
void usage()
{
	printf("usage:\t./a.out sowmya.txt word\n");
}
int main(int argc,char *argv[])
{
	FILE *fp;
	char fline[MAX];
	char *newline;
	int count=0;
	int occurances=0;
	if(argc!=3)
	{
		usage();
		exit(1);
	}
	fp=fopen(argv[1],"r");
	if(!fp)
	{
		printf("grep:could not open file:%s\n",argv[1]);
		exit(1);
	}
	while(fgets(fline,MAX,fp)!=NULL)
	{
		count++;
		if((newline=strchr(fline,'\n'))!=NULL);
		{
			printf("no occurances of word '%s' found.\n",argv[2]);
		}
		if(occurances==0)
		{
			printf("no occurances of the word '%s' found.\n",argv[2]);
		}
		fclose(fp);
		return 0;
	}
} 
compilatoin steps
gcc filename.c -o filename
./filename word_to_search
