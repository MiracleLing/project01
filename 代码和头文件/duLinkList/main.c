#include<stdio.h>
#include<stdlib.h>
#include "E:\project1\QGѵ��Ӫ��һ����ѵ\�����ͷ�ļ�\head\duLinkedList.h"
int main()
{
	DuLinkedList st;
	DuLNode *added=st,*add;
	int search,i,dele,order;
    
    st=create_List();
    TraverseList_DuL(st,(*visit));
    
    //�˵����� 
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("                 ***************************************�����˵�**********************************\n");
    printf("                 *                                 1.�½�һ������                                *\n");
    printf("                 *                                 2.�����ǰ����                                *\n");
    printf("                 *                                 3.���ٵ�ǰ����                                *\n");
    printf("                 *                                 4.ɾ�����                                    *\n");
    printf("                 *                                 5.��ǰ�������                              *\n");
    printf("                 *                                 6.��ǰ�������                              *\n");
    printf("                 *                                 7.�˳�����                                    *\n");
    printf("                 *********************************************************************************\n");
    while(order!=7)
	{
	printf("\n������ָ�");//����ָ����ת����Ӧ���� 
    scanf("%d",&order);
    switch (order)
	{
	case 1:st=create_List();break;
	case 2:TraverseList_DuL(st,(*visit));break;
	case 3:DestroyList_DuL(&st);break;
	case 4:DeleteList_DuL(st,&dele);break;
	case 5:InsertBeforeList_DuL(st,add);break;
	case 6:InsertAfterList_DuL(st,add);break;
	case 7:;break;
	default:fflush(stdin);printf("δ�ҵ���ָ�\n");break; 
	}	
	}
   printf("\n��л����ʹ�ã�\n");
}
