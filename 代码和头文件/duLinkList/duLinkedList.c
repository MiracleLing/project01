#include "E:\project1\QG训练营第一次培训\代码和头文件\head\duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) 
{	
	*L=(DuLinkedList)malloc(sizeof(DuLNode));
	if((*L)==NULL)
		{ 
		return ERROR;
		} 
	(*L)->next=(*L)->prior=NULL;
	return SUCCESS;
}


//创建链表 
DuLinkedList create_List()	
{	
	DuLNode *ppp,*pp,*p,*L;
	int n=0;
	InitList_DuL(&L);
	InitList_DuL(&ppp);
	InitList_DuL(&pp);
	InitList_DuL(&p);
		
	printf("请输入数据创建链表(输入-1结束)：\n");//输入数据 
	printf("序号 数据\n");
	
	do
	{
		n=n+1;// 当输入数据不为0时创建链表 
		printf("%d.   ",n);
		while(!(scanf("%d",&ppp->data)))
		 {  
		 	printf("该数据并非整数,请重新输入！\n");
		 	printf("%d.   ",n);	
		 	fflush(stdin);
		  } 
		  
		if(n==1&&ppp->data==-1)
		{	ppp=NULL;
			return ppp;
		}
		if(ppp->data!=-1)
		{	
			if(n==1)
			{
				p=ppp;
				L=p;
			}	 	
				if(n!=1)	
				{
					pp=ppp;			
					p->next=pp;
	   				pp->next=ppp; 
	   				pp->prior=pp;
					p=p->next;
				}
			InitList_DuL(&ppp);		 		 			
	    }
	}while(ppp->data!=-1);
	pp->next=NULL;
	return L;
}


/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) 
{
	DuLinkedList p;
	
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
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) 
{
	DuLNode *head,*k;
	int insert,i;
	head=p;
	InitList_DuL(&q);

	printf("请输入插入结点位置及数据：\n");
	printf("例如：3 400代表在第三个结点前插入数据400。\n");  	
	while((scanf("%d %d",&insert,&q->data))!=2)
		 {  
		    
		 	printf("输入格式错误,请重新输入！\n");	
			fflush(stdin);
		  } 
	
	if(insert<=1)
	{
		printf("该节点前面为空！\n");
		return ERROR;	
	}	  
	if(!p)
		{
		printf("该链表为空！\n"); 
		return ERROR;
		}	
	for(i=2;i<insert;i++)
		{
		p=p->next;
		if(!p||!p->next) 
		{
			printf("该结点或其下一位为空！\n"); 
			return ERROR;
		}
		}	
		
		p=p->prior;
		q->next=p->next;
		p->next->prior=q;
		q->prior=p;
		p->next=q;	
			
	printf("\n"); 
	printf("插入后"); 
	TraverseList_DuL(head,(*visit));
	return SUCCESS;	
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) 
{	
	DuLNode *head;
	int insert,i;
	head=p;
	InitList_DuL(&q);

	printf("请输入插入结点位置及数据：\n");
	printf("例如：3 400代表在第三个结点后插入数据400。\n");  	
	
	
	while((scanf("%d %d",&insert,&q->data))!=2)
		 {  
		    fflush(stdin);
		 	printf("输入格式错误,请重新输入！\n");	
		  } 
		  
	if(insert<=0)
	{
		printf("该节点前面为空！\n");
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
		if(!p||!p->next) 
		{
			printf("该结点或其下一位为空！\n"); 
			return ERROR;
		}
		}	
	
		q->next=p->next;
		p->next->prior=q;
		q->prior=p;
		p->next=q;	
	
	printf("\n"); 
	printf("插入后"); 
	TraverseList_DuL(head,(*visit));
	return SUCCESS;	

}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) 
{
	int n,i;
	DuLNode *q;
	
	printf("输入数字删除后一位结点：\n");//用户输入结点位置 
	printf("例如：输入3将删除第三个结点后面一个结点。\n");
	while((scanf("%d",&n))!=1)
		 {  
		 	printf("输入格式错误,请重新输入！\n");
			fflush(stdin);	
		  } 
	if(n<=0)
	{
		printf("该结点无法删除！\n");
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
	q->next->prior=p;
	free(q);
	printf("被删结点的数据为：%d",*e);
	printf("\n\n");
	
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) 
{
	DuLNode *p;
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
