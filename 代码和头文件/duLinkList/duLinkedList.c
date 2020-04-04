#include "E:\project1\QGѵ��Ӫ��һ����ѵ\�����ͷ�ļ�\head\duLinkedList.h"
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


//�������� 
DuLinkedList create_List()	
{	
	DuLNode *ppp,*pp,*p,*L;
	int n=0;
	InitList_DuL(&L);
	InitList_DuL(&ppp);
	InitList_DuL(&pp);
	InitList_DuL(&p);
		
	printf("���������ݴ�������(����-1����)��\n");//�������� 
	printf("��� ����\n");
	
	do
	{
		n=n+1;// ���������ݲ�Ϊ0ʱ�������� 
		printf("%d.   ",n);
		while(!(scanf("%d",&ppp->data)))
		 {  
		 	printf("�����ݲ�������,���������룡\n");
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

	printf("�����������λ�ü����ݣ�\n");
	printf("���磺3 400�����ڵ��������ǰ��������400��\n");  	
	while((scanf("%d %d",&insert,&q->data))!=2)
		 {  
		    
		 	printf("�����ʽ����,���������룡\n");	
			fflush(stdin);
		  } 
	
	if(insert<=1)
	{
		printf("�ýڵ�ǰ��Ϊ�գ�\n");
		return ERROR;	
	}	  
	if(!p)
		{
		printf("������Ϊ�գ�\n"); 
		return ERROR;
		}	
	for(i=2;i<insert;i++)
		{
		p=p->next;
		if(!p||!p->next) 
		{
			printf("�ý�������һλΪ�գ�\n"); 
			return ERROR;
		}
		}	
		
		p=p->prior;
		q->next=p->next;
		p->next->prior=q;
		q->prior=p;
		p->next=q;	
			
	printf("\n"); 
	printf("�����"); 
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

	printf("�����������λ�ü����ݣ�\n");
	printf("���磺3 400�����ڵ����������������400��\n");  	
	
	
	while((scanf("%d %d",&insert,&q->data))!=2)
		 {  
		    fflush(stdin);
		 	printf("�����ʽ����,���������룡\n");	
		  } 
		  
	if(insert<=0)
	{
		printf("�ýڵ�ǰ��Ϊ�գ�\n");
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
		if(!p||!p->next) 
		{
			printf("�ý�������һλΪ�գ�\n"); 
			return ERROR;
		}
		}	
	
		q->next=p->next;
		p->next->prior=q;
		q->prior=p;
		p->next=q;	
	
	printf("\n"); 
	printf("�����"); 
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
	
	printf("��������ɾ����һλ��㣺\n");//�û�������λ�� 
	printf("���磺����3��ɾ��������������һ����㡣\n");
	while((scanf("%d",&n))!=1)
		 {  
		 	printf("�����ʽ����,���������룡\n");
			fflush(stdin);	
		  } 
	if(n<=0)
	{
		printf("�ý���޷�ɾ����\n");
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
	q->next->prior=p;
	free(q);
	printf("��ɾ��������Ϊ��%d",*e);
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
