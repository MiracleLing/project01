#include"E:\project1\QGѵ��Ӫ��һ����ѵ\�����ͷ�ļ�\head\linkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main()
{	
	LinkedList st;
	LNode *added=st,*add;
	int search,i,dele,order;
	
	st=create_List();//�������ݴ������� 
    TraverseList(st,(*visit));//��������
    
    //�˵����� 
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("                 ***************************************�����˵�**********************************\n");
    printf("                 *                                 1.�½�һ������                                *\n");
    printf("                 *                                 2.�����ǰ����                                *\n");
    printf("                 *                                 3.���ٵ�ǰ����                                *\n");
    printf("                 *                                 4.������                                    *\n");
    printf("                 *                                 5.ɾ�����                                    *\n");
    printf("                 *                                 6.�������                                    *\n");
	printf("                 *                                 7.��ת����                                    *\n");
    printf("                 *                                 8.�ж������Ƿ�ɻ�                            *\n");
    printf("                 *                                 9.�˳�����                                    *\n");
    printf("                 *********************************************************************************\n"); 
    while(order!=9)
	{
	printf("\n��������ȷָ�");//����ָ����ת����Ӧ���� 
	getchar();
    scanf("%d",&order);
    switch (order)
	{
	case 1:st=create_List();break;
	case 2:TraverseList(st,(*visit));break;
	case 3:DestroyList(&st);;break;
	case 4:InsertList(st,add);break;
	case 5:DeleteList(st, &dele);break;
	case 6:SearchList(st, search);break;
	case 7:ReverseList(&st);break;
	case 8:IsLoopList(st);break;
	case 9:;break;
	default:getchar();printf("δ�ҵ���ָ�\n");fflush(stdin);break; 
	}
	}	
	printf("\n��л����ʹ�ã�\n");
    return 0;

}



