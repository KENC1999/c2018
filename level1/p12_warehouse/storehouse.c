#include <stdio.h>
#include <stdlib.h>
int amount,c,d,e;
int judge=0;
struct item
{
	int action;
	char name[100];
	int amount;
}ware[10000];

void begin();
void menu(); 
void display();

int main(int argc, char *argv[]) 
{
	//begin();
	while(1)
	{
		menu();
		if(1==judge)break;
	} 
	printf("see you!\n") ;
	return 0;
}

void menu()
{
	beginning:system("cls");
	printf("�˵�\n1����ʾ����б�\n2�����\n3������\n4���˳�����\n���������ѡ��\n");
	int choice=0;
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			display();
			break;
		case 2:
			import();
			break;
		case 3:
			export();
			break;
		case 4:
			judge=1;
		default:
			break;
	}
}



void begin()
{
	FILE *fp=fopen("warehouse.txt","rb");
	if(fp == NULL)
    return -1;
    while(!feof(fp))
    {
    	fscanf("%d",&e);
    	fscanf("%s%d",ware[e].name,&ware[e].amount);
	}
	fclose(fp);
}

void display()
{
	char ch;
	system("cls");
	FILE *fp;
	fp=fopen("warehouse.txt","w");
	int i=1;
	for(i=1;i<10000;i++)
	{
		if(ware[i].action==1)
		fprintf(fp,"%d %s %d\n",i,ware[i].name,ware[i].amount);
	}
	fp=fopen("warehouse.txt","r");
	ch=fgetc(fp);
    while(ch!=EOF)
    {
        putchar(ch);
        ch=fgetc(fp);
    }
    printf("\n");
	fclose(fp);
	printf("����������ز˵�\n");
	ch=getchar();
}
void import()
{
	printf("������\n");
	scanf("%d",&c);
	//ware[c].number=c;
	ware[c].action=1;
	printf("��������Ҫ����Ļ�������\n");
	scanf("%s",&ware[c].name);
	printf("��������\n");
	scanf("%d",&ware[c].amount);
 } 
 
 void export()
 {
	printf("������\n");
	scanf("%d",&c);
	printf("��Ҫȡ���Ļ�������:%s\n",ware[c].name);
	printf("����ȡ������\n");
	scanf("%d",&d);
	ware[c].amount-=d;
	return;
 }
