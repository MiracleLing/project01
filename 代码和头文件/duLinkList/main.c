#include<stdio.h>
#include<stdlib.h>
#include "E:\project1\QG训练营第一次培训\代码和头文件\head\duLinkedList.h"
int main()
{
	DuLinkedList st;
	DuLNode *added=st,*add;
	int search,i,dele,order;
    
    st=create_List();
    TraverseList_DuL(st,(*visit));
    
    //菜单界面 
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("                 ***************************************操作菜单**********************************\n");
    printf("                 *                                 1.新建一个链表                                *\n");
    printf("                 *                                 2.浏览当前链表                                *\n");
    printf("                 *                                 3.销毁当前链表                                *\n");
    printf("                 *                                 4.删除结点                                    *\n");
    printf("                 *                                 5.从前面插入结点                              *\n");
    printf("                 *                                 6.从前面插入结点                              *\n");
    printf("                 *                                 7.退出程序                                    *\n");
    printf("                 *********************************************************************************\n");
    while(order!=7)
	{
	printf("\n请输入指令：");//输入指令跳转至对应函数 
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
	default:fflush(stdin);printf("未找到该指令！\n");break; 
	}	
	}
   printf("\n感谢您的使用！\n");
}
