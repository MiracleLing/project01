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
//�������� 
LinkedList create_List()	
{	
	LNode *last,*p,*L;
	int n=0;
	InitList(&L);
	InitList(&last);
	InitList(&p);	
	
	printf("����������(����-1����)��\n");//�������� 
	printf("��� ����\n");
	
	do{	n=n+1;// ���������ݲ�Ϊ0ʱ�������� 
		printf("%d.   ",n);
		while(!(scanf("%d",&last->data)))
		{  
		    printf("�����ݲ�������,���������룡\n");
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
	
	while(*L)//��������
	{
		p=(*L)->next;
		free(*L);
		*L=p;	
	}
		if((*L)==NULL)//�ж��Ƿ����ٳɹ� 
			printf("���ٳɹ���");
		else
			printf("����ʧ�ܣ�");
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

	printf("�����������λ�ü����ݣ�\n");
	printf("���磺3 400�����ڵ����������������400��\n");  	
	while((scanf("%d %d",&insert,&q->data))!=2)
		 {  
		 	printf("�����ʽ����,���������룡\n");
		 	fflush(stdin);
		  } 
	
	if(insert<=0)
	{
		printf("�ý��λ�ò����ڣ�\n");
		return ERROR; 
	}	  
	if(!p)
		{
		printf("������Ϊ�գ�\n"); 
		return ERROR;
		}
			
	for(i=1;i<insert;i++)
		{
		p=p->next;
		if(p==NULL||p->next==NULL)
		{
		printf("�ý����һλ�޷��������ݣ�\n");
		return ERROR;
		}
		}	
	
		q->next=p->next;
		p->next=q;
	
	printf("\n"); 
	printf("�����"); 
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

	printf("��������ɾ����һλ��㣺\n");//�û�������λ�� 
	printf("���磺����3��ɾ��������������һ����㡣\n");
	while((scanf("%d",&n))!=1)
		 {  
		 	printf("�����ʽ����,���������룡\n");
		 	printf("%d.   ",n);	
		 	fflush(stdin);
		  } 
	if(n<=0)
	{
		printf("�ý��λ���޷�ɾ����\n");
		return ERROR; 
	}
	if(!p||!p->next) //�ҵ���Ӧ���
		{
			printf("������Ϊ�գ�\n"); 
			return ERROR;
		}
	for(i=1;i<n;i++) 
		{
		p=p->next;
		if(!p||!p->next) 
		{
			printf("�ý�������һλΪ�գ�\n"); 
			return ERROR;
		}
		}	
	 	
	q=p->next;//ɾ����㲢��������ֵ
	*e=q->data;
	p->next=q->next;
	free(q);
	printf("��ɾ��������Ϊ��%d",*e);
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
	
	printf("�����������£�\n");
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
	printf("������Ҫ���������ݣ�"); 
    	while((scanf("%d",&e))!=1)
		 {  
		 	printf("�����ʽ����,���������룡\n");
		 	fflush(stdin);
		  } 
    
	LNode *p;
	int n=1;
	p=L;
	
	while(p)
	{
		if(p->data==e)
			{
				printf("�������е�%d������ҵ��˸����ݣ�\n\n",n);
				return SUCCESS;
			}
		else
			p=p->next;
			n++;
	}
	printf("δ�ҵ������ݣ�\n\n");
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
		{	printf("������Ϊ�գ�\n");
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
		printf("��ת��");
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
			printf("������ɻ���"); 
			printf("\n");
			return SUCCESS; 
		}	
	}
	printf("�������ɻ���");
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




