#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
	int d;
	struct node *next;
} ;
struct node *head,*p,*q;
//查找一个节点
void find(struct node *head,int x)
{
	int i=1;
	struct node *this;
	this =head;
	while((this !=NULL)&&!(this->d==x)){
		this=this->next;
		i++;
	}
	if(this==NULL)
		printf("没有找到！\n");
	else 
		printf("%d在链表的第%d个结点中！\n",x,i);
}
//插入新节点函数
void ins(struct node *head,struct node *p,int j,int s)
{
	int a=1;	
	struct node *new,*this;
	new=malloc(sizeof(struct node));
	this=head;
	while(this!=NULL&&!(this->d==j)){
		this=this->next;
		a++;
	}
	if(j!=10){
		new->d=s;
		new->next=p->next;
		p->next=new;
	}
	else{
		new->d=s;
		new->next=this->next;
		this->next=new;
	}
}
//删除节点
void del(struct node *head,int b)
{
	struct node *new,*this;
	this=head;
	if(this->d==b){
		this=head->next;
		free(head);
		head=this;
	}
	else{
		while(this->next!=NULL){
			new=this->next;
			if(new->d==b){
				this->next=new->next;
				free(new);
			}
			else		       
				this=this->next;
		}
	}
}
	void print()
	{
	for(q=head;q!=NULL;q=q->next)
		printf("%d",q->d);
	printf("\n");
}
int main()
{

	int i,n,x,s,j,b,a;
	head=malloc(sizeof(struct node));//创建初始链表
	head->d=1;
	head->next=NULL;
	q=head;
	for(i=2;i<=10;i++){
		p=malloc(sizeof(struct node));
		q->next=p;
		p->d=i;
		p->next=NULL;
		q=p;
	}
	printf("当前链表内数字\n");
	print();
        printf("输入命令1：查询数字位置\n输入命令2：增加数字\n输入命令3：删除数字\n");
	printf("请输入命令数字(1-3):");
	scanf("%d",&a);
	switch(a){
		case 1:
			printf("请输入要查找的数字:");
			scanf("%d",&x);
			find(head,x);
			break;
		case 2:	
			printf("在节点后增加的数字：");
			scanf("%d %d",&j,&s);
			ins(head,p,j,s);
			print();
			break;
		case 3:
			printf("删除节点：");
			scanf("%d",&b);
			del(head,b);
			print();
			break;
		default:printf("error\n");
	} 
	return 0;
}

