#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct allocate
{
	int pid;
	int st_add;
	int end_add;
	struct allocate *next;
};
struct free_list
{
	int st_add;
	int end_add;
};
struct porcess
{
	int pid;
	int size;
};
struct porcess pro[10];
struct free_list *first=NULL;
sturct allocate *alot=NULL;
void display_alot(struct allocate *temp_a)
{
	printf("\n\nallocated list:");
	printf("\n=====");
	while(temp_a!=NULL)
	{
		printf("\nprocess:%d st_add:%d end_add:%d",temp_a->pid,temp_a->st_add,temp_a->end_add);
		temp.a=temp.a->next;
	}
}
void display_free(struct free_list *temp_f)
{
	printf("\n\nfree list:");
	printf("\n=====");
	while(temp_f!=NULL)
	{
		printf("\nst_add:%d end_add:%d",temp_f->st_add,temp_f->end_add);
		temp_f=temp_f->next;
	}
}
void insert(int p)
{
	struct free_list *temp_f;
	struct allocate *temp_a,*pre_a;
	int n,i;
	do
	{
		srand((unsigned int)time((time_t*)NULL));
		n=rand()%5;
	}
	while(n==0);
	printf("\n\nno.of process:%d",n);
	for(i=0;i<n;i++)
	{
		pro[i].pid=i+p;
		do
		{
			pro[i].size=rand()%300;
		}
		while(por[i].size==0);
	}
	for(i=0;i<n;i++)
	{
		printf("\n\nprocess to be inserted :%d size:%d",pro[i].pid,pro[i].size);
		temp_f=flist;
		temp_a=alot;
		while(temp_f!=NULL && temp_f->end_add-temp_f->st_add<pro[i].size)
		{
			temp_f=temp_f->next;
		}
		
