#include"E:\project1\QG训练营第一次培训\代码和头文件\head\linkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main()
{	
	LinkedList st;
	LNode *added=st,*add;
	int search,i,dele,order;
	
	st=create_List();//输入数据创建链表 
    TraverseList(st,(*visit));//遍历链表
    
    //菜单界面 
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("                 ***************************************操作菜单**********************************\n");
    printf("                 *                                 1.新建一个链表                                *\n");
    printf("                 *                                 2.浏览当前链表                                *\n");
    printf("                 *                                 3.销毁当前链表                                *\n");
    printf("                 *                                 4.插入结点                                    *\n");
    printf("                 *                                 5.删除结点                                    *\n");
    printf("                 *                                 6.搜索结点                                    *\n");
	printf("                 *                                 7.反转链表                                    *\n");
    printf("                 *                                 8.判断链表是否成环                            *\n");
    printf("                 *                                 9.退出程序                                    *\n");
    printf("                 *********************************************************************************\n"); 
    while(order!=9)
	{
	printf("\n请输入正确指令：");//输入指令跳转至对应函数 
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
	default:getchar();printf("未找到该指令！\n");fflush(stdin);break; 
	}
	}	
	printf("\n感谢您的使用！\n");
    return 0;

}



