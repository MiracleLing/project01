#include "E:\project01\QG1\1\head\linkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */

Status InitList(LinkedList *L)
{	
	*L=(LinkedList)malloc(sizeof(LinkedList));
	if((*L)==NULL)
		{ 
		return ERROR;
		} 
	(*L)->next=NULL;
	return SUCCESS;
}
//创建链表 
LinkedList create_List()	
{	
	LNode *last,*p,*L;
	int n=0;
	InitList(&L);
	InitList(&last);
	InitList(&p);	
	
	printf("请输入数据(输入-1结束)：\n");//输入数据 
	printf("序号 数据\n");
	
	do{	n=n+1;// 当输入数据不为0时创建链表 
		printf("%d.   ",n);
		while(!(scanf("%d",&last->data)))
		{  
		    printf("该数据并非整数,请重新输入！\n");
		 	printf("%d.   ",n);	
		 	fflush(stdin);	
		} 
		
		if(n==1&&last->data==-1)
		{	last=NULL;
			return last;
		}
		if(last->data!=-1)
			{	p=last;		
				InitList(&last);
	   			p->next=last; 
				if(n==1)
				 	L=p;	 		 			
	    	}
		}while(last->data!=-1);
	p->next=NULL;
	return L;
}
	/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) 
{
	LinkedList p;
	
	while(*L)//销毁链表
	{
		p=(*L)->next;
		free(*L);
		*L=p;	
	}
		if((*L)==NULL)//判断是否销毁成功 
			printf("销毁成功！");
		else
			printf("销毁失败！");
	printf("\n\n");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) 
{	
	LNode *head;
	int insert,i;
	head=p;
	InitList(&q);

	printf("请输入插入结点位置及数据：\n");
	printf("例如：3 400代表在第三个结点后插入数据400。\n");  	
	while((scanf("%d %d",&insert,&q->data))!=2)
		 {  
		 	printf("输入格式错误,请重新输入！\n");
		 	fflush(stdin);
		  } 
	
	if(insert<=0)
	{
		printf("该结点位置不存在！\n");
		return ERROR; 
	}	  
	if(!p)
		{
		printf("该链表为空！\n"); 
		return ERROR;
		}
			
	for(i=1;i<insert;i++)
		{
		p=p->next;
		if(p==NULL||p->next==NULL)
		{
		printf("该结点下一位无法插入数据！\n");
		return ERROR;
		}
		}	
	
		q->next=p->next;
		p->next=q;
	
	printf("\n"); 
	printf("插入后"); 
	TraverseList(head,(*visit));
	return SUCCESS;	
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e)
{	int n,i;
	LNode *q;

	printf("输入数字删除后一位结点：\n");//用户输入结点位置 
	printf("例如：输入3将删除第三个结点后面一个结点。\n");
	while((scanf("%d",&n))!=1)
		 {  
		 	printf("输入格式错误,请重新输入！\n");
		 	printf("%d.   ",n);	
		 	fflush(stdin);
		  } 
	if(n<=0)
	{
		printf("该结点位置无法删除！\n");
		return ERROR; 
	}
	if(!p||!p->next) //找到对应结点
		{
			printf("该链表为空！\n"); 
			return ERROR;
		}
	for(i=1;i<n;i++) 
		{
		p=p->next;
		if(!p||!p->next) 
		{
			printf("该结点或其下一位为空！\n"); 
			return ERROR;
		}
		}	
	 	
	q=p->next;//删除结点并返回其数值
	*e=q->data;
	p->next=q->next;
	free(q);
	printf("被删结点的数据为：%d",*e);
	printf("\n\n");
	
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L,void (*visit)(ElemType e)) 
{
	LNode *p;
	p=L;
	
	printf("所得链表如下：\n");
	while(p!=NULL)
	{
		visit(p->data);
		p=p->next;
		printf("->");		
	}
	printf("NULL");
	printf("\n\n");	
}
void visit(ElemType e)
{
	printf("%d",e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) 
{	
	printf("请输入要搜索的数据："); 
    	while((scanf("%d",&e))!=1)
		 {  
		 	printf("输入格式错误,请重新输入！\n");
		 	fflush(stdin);
		  } 
    
	LNode *p;
	int n=1;
	p=L;
	
	while(p)
	{
		if(p->data==e)
			{
				printf("在链表中第%d个结点找到了该数据！\n\n",n);
				return SUCCESS;
			}
		else
			p=p->next;
			n++;
	}
	printf("未找到该数据！\n\n");
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) 
{	
	LNode* p,*q,*r;
	if((*L)==NULL)
		{	printf("该链表为空！\n");
			return ERROR;
		}
	p=*L;
	q=(*L)->next;
	(*L)->next=NULL;
	
	while(q)
		{
			r=q->next;
			q->next=p;
			p=q;
			q=r;
		}
		L=&p;	
		printf("翻转后");
		TraverseList(p,(*visit));
		printf("\n");
		return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) 
{
	LNode *fast,*slow;
	fast=slow=L;
	while(fast&&fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			printf("该链表成环！"); 
			printf("\n");
			return SUCCESS; 
		}	
	}
	printf("该链表不成环！");
	printf("\n"); 
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {

}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {

}




