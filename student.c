#include"student2.h"

int main()
{
	int n=0, m=0;		//输入人数以及课程数
	int x;				//搜索学生的学号

	int exist1=0;		//教师端登出标记
	int exist2=0;		//学生端登出标记

	int flag=0;			//是否输入信息，默认为0，即没有

	system("color F0");

	STU* Head;			//学生信息头指针,没有实际值
	Head = (STU*)malloc(sizeof(STU));
	Head->next = NULL;

	USER users[100];
	int num=0;			//用户数量计数器

	int Choice;			//用户选择
	int choice;			//教师端选择
	int choice1;		//学生端选择

	while(1)			//最外层循环
	{
		system("cls");
		choice=MenuLoad(&x,&num,users);
		switch(choice)
		{
			case 0:
			    system("cls");
				GotoXY(40,16);
				printf("注册成功\n");
				system("pause");
				break;
			case 2:
				system("cls");
				GotoXY(40,16);
				printf("用户名或密码错误\n");
				system("pause");
				break;
			case 3:
				system("cls");
				GotoXY(40,16);
				printf("选择错误\n");
				system("pause");
				break;	
			case 4:
				exit(1);
				break;
			case 6:
				system("cls");
				GotoXY(40,16);
				printf("职称输入错误\n");
				system("pause");
				break;
			case 5:
				system("cls");
				GotoXY(40,14);
				printf("欢迎学生登录！\n");
				system("pause");
				exist2=0;
				while(!exist2)
				{
					system("cls");
					choice1=Menu1();
					switch(choice1)
					{
						case 0:
							exist2=1;
							break;
						case 1:
							if(!flag)
							{
								system("cls");
								GotoXY(40,10);
								printf("成绩还未刊登，请等待");
								system("pause");
								break;
							}
							else
							{
								system("cls");
								DataSearch(x,m,Head);
								system("pause");
								break;
							}
					}
				}
			break;
			case 1:
				system("cls");
				GotoXY(40,14);
				printf("登录成功\n");
				system("pause");
				exist1=0;
				while (!exist1)						//内层循环
				{
				system("cls");
				Choice = Menu();
				switch (Choice)
				{
				case 1:	
					if(flag)					//输入函数
					{
						system("cls");
						GotoXY(40,10);
						printf("已输入过数据，如需增添请进行操作3！\n");
						system("pause");
						break;
					}	
					else
					{
						system("cls");
						DataInput(&n, &m, Head);
						flag=1;
						break;
					}					

				case 2:							//输出函数
					system("cls");
					if(!flag)
					{
						printf("暂未输入信息\n");
						system("pause");
						break;
					}	
					else
					{
						DataOutput(&m, Head);
						system("pause");
						break;
					}				
				case 3:		
					system("cls");					//信息增加函数
					if(!flag)
					{
						printf("暂未输入信息\n");
						system("pause");
						break;
					}	
					else
					{
						DataInsert(m,Head);
						break;
					}				
				case 4:
					system("cls");
					if(!flag)
					{
						printf("暂未输入信息\n");
						system("pause");
						break;
					}	
					else
					{
						GotoXY(40,6);
    					printf("查找学生的学号：");
    					scanf("%d",&x);
						system("cls");
						DataSearch(x,m,Head);
						system("pause");
						break;
					}
				case 5:
					system("cls");
					if(!flag)
					{
						printf("暂未输入信息\n");
						system("pause");
						break;
					}	
					else
					{
						DataReset(m,Head);
						break;
					}		
				case 6:
					system("cls");
					if(!flag)
					{
						printf("暂未输入信息\n");
						system("pause");
						break;
					}	
					else
					{
						DataDelete(Head);
						break;
					}
				case 7:
					system("cls");
					if(!flag)
					{
						printf("暂未输入信息\n");
						system("pause");
						break;
					}	
					else
					{
						DataSort1(Head);
						break;
					}	
				case 8:
					system("cls");
					if(!flag)
					{
						printf("暂未输入信息\n");
						system("pause");
						break;
					}	
					else
					{
						Write_file(m,Head);
						break;
					}
				case 9:
					if(!flag)
					{
						system("cls");
						Read_file(&n,&m,Head);
						flag=1;
						break;	
					}
					else
					{
						GotoXY(40,14);
						printf("数据已导入");
						system("pause");
						break;
					}
				case 10:
					if(flag)
					{
						system("cls");
						DataProduct(m,Head);
						break;	
					}
					else
					{
						GotoXY(40,14);
						printf("数据未读入");
						system("pause");
						break;
					}	
				case 11:
					if(flag)
					{
						system("cls");
						DataCount(n,m,Head);
						break;
					}		
					else
					{
						GotoXY(40,14);
						printf("信息未录入\n");
						system("pause");
						break;
					}
				case 12:
					if(flag)
					{
						system("cls");
						DataSort2(Head);
						break;
					}
					else{
						GotoXY(40,14);
						printf("信息未录入\n");
						system("pause");
						break;						
					}
								
				case 0:							//退出系统
					system("cls");
					GotoXY(0, 10);
					printf("退出系统！\n");
					exist1=1;
					break;
				default:						//无效输出
					system("cls");
					GotoXY(0, 10);
					printf("输入出错，请重新选择操作！\n");
					system("pause");
				}
			
			}
			
		}
	}
	return 0;
}