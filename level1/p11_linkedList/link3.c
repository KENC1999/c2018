#include<stdio.h>
#include<stdlib.h>

int count[50]={0}; 
struct student
{
	int num;
	struct stduent *next;
};
int main()
{
	int a=0; 
	struct student *head,*current,*already;
	current=head=(struct student*)malloc(sizeof(struct student));
	printf("����0����\n");
	scanf("%d",&current->num);
	count[a]=current->num;
	while(current->num!=0)
	{
		a++;
		already=current;
		current=(struct student*)malloc(sizeof(struct student));
		scanf("%d",&current->num);
		count[a]=current->num;
		already->next=current;
	}
	current->next=NULL;
	printf("------------------��������--------------------\n");
	current=head;
	while(current->next!=NULL)
	{
		printf("%d\n",current->num);
		current=current->next;
	}
	printf("%d\n",current->num);
	printf("------------------�ڵ�Ϊ5�����-------------------\n");
	current=head;
	int i=0,g=0;
	while(current->next!=NULL)  
        { 
          	i++;
          	if(current->num==5)
          	{
		  		printf("%d\n",i);
		  		g=g+1;
			}
          	current=current->next;  
        }
    i++;
    if(current->num==5)
    {
		printf("%d\n",i);
		g++;
	}
	if(g==0)
	printf("-1\n"); 
	printf("------------------��������-------------------\n") ;
	while(a>=0)
	{
		printf("%d\n",count[a]);
		a--;
	}
	return 0;
}
