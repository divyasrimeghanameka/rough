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
	struct free_list *next;
};
struct process
{
	int pid;
	int size;
};
struct process pro[10];
struct free_list* flist=NULL;
struct allocate* alot=NULL;
void display_alot(struct allocate *temp_a)
{
	printf("\n\nallocated list:");
	printf("\n=====");
	while(temp_a!=NULL)
	{
		printf("\nprocess:%d st_add:%d end_add:%d",temp_a->pid,temp_a->st_add,temp_a->end_add);
		temp_a=temp_a->next;
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
	struct free_list* temp_f;
	struct allocate* temp_a, *pre_a;
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
		while(pro[i].size==0);
	}
	for(i=0;i<n;i++)
	{
		printf("\n\nprocess to be inserted :%d size:%d",pro[i].pid,pro[i].size);
		temp_f = flist;
		temp_a=alot;
		while(temp_f!=NULL && temp_f->end_add-temp_f->st_add<pro[i].size)
		{
			temp_f=temp_f->next;
		}
		if(temp_f!=NULL)
		{
		        pre_a=(struct allocate*)malloc(sizeof(struct allocate));
		        pre_a->st_add=temp_f->st_add;
		        pre_a->end_add=temp_f->st_add+pro[i].size;
		        pre_a->pid=pro[i].pid;
		        temp_f->st_add+=pro[i].size;
		        if(temp_a==NULL)
		        {
		            alot=pre_a;
		            pre_a->next=NULL;
		        }
		        else
		        {
		            while(temp_a->next!=NULL)
		            {
		                temp_a=temp_a->next;
		            }
		            temp_a->next=pre_a;
		            pre_a->next=NULL;
		        }
		}
		else
		{
		    printf("\nthere is not enough space");
		    display_alot(alot);
		    display_free(flist);
		}
	}
}
void main()
{
    int no,n,i,nod,ndpid;
    struct process pro[10];
    struct free_list*temp_f,*free_alot,*pre_f;
    struct allocate*temp_a,*pre_a;
    alot=NULL;
    flist = (struct free_list*)malloc(sizeof(struct free_list));
    flist->st_add=0;
    flist->end_add=1024;
    flist->next=NULL;
    insert(0);
    do
    {
        srand((unsigned int)time((time_t*)NULL));
        nod=rand()%2;
    }
    while(nod==0);
    printf("\n\nno.of process deletion:%d",nod);
    for(i=0;i<nod;i++)
    {
        printf("\n\n\nprocess to be deleted:");
        scanf("%d",&ndpid);
        temp_a=alot;
        temp_f=flist;
        while(temp_a!=NULL && temp_a->pid!=ndpid)
        {
            pre_a=temp_a;
            temp_a=temp_a->next;
        }
        if(temp_a!=NULL)
        {
            if(alot==temp_a)
                alot=temp_a->next;
            else
            {
                pre_a->next=temp_a->next;
                pre_f=NULL;
            }
            while(temp_f!=NULL && temp_f->st_add<temp_a->st_add)
            {
                pre_f=temp_f;
                temp_f=temp_f->next;
            }
            if(pre_f!=NULL && pre_f->end_add==temp_a->st_add)
                pre_f->end_add=temp_a->end_add;
            else if(pre_f!=NULL && temp_f!=NULL && temp_f->st_add==temp_a->end_add)
                temp_f->st_add=temp_a->st_add;
            else
            {
                free_alot=(struct free_list*)malloc(sizeof(struct free_list));
                free_alot->st_add=temp_a->st_add;
                free_alot->end_add=temp_a->end_add;
                if(pre_f!=NULL)
                    pre_f->next=free_alot;
                free_alot->next=temp_f;
                if(flist==temp_f)
                {
                    flist=free_alot;
                }
            }free(temp_a);
        }
        else 
            printf("\nprocess not in memory");
            temp_f=flist;
            while(temp_f!=NULL)
            {
                if(temp_f->end_add==temp_f->next->st_add)
                {
                    temp_f->end_add=temp_f->next->end_add;
                    temp_f->next=temp_f->next->next;
                }
                temp_f=temp_f->next;
            }
            display_alot(alot);
            display_free(flist);
    }
        insert(10);
}
		
