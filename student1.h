#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>

#define STU_NUM 50      //学生人数
#define COURSE_NUM 10   //课程上限
#define NAME_LEN 10     //名字最大上限

/*学生结构体*/
typedef struct student
{
    long num;               //学号
    char name[NAME_LEN];    //姓名
    float score[COURSE_NUM];//课程成绩
    float sum;              //总分
    float aver;             //平均分
    int rank;               //排名
    struct student* next;   //指针
}STU;

/*定义用户结构体*/
typedef struct user
{
    char position[20];
    char* name[20];
    char* password[20]; 
    int num;
}USER;


/*函数定义*/
void GotoXY(int x, int y);                                 //光标定位函数
int Menu();                                                //教师端主菜单
int Menu1();                                               //学生端菜单
int MenuLoad(int *x,int* num,USER* users);                 //用户注册/登录界面
void DataInput(int* n,int* m, STU* head);                  //信息输入函数
void DataOutput(int* m,STU* head);                         //信息输出函数
void DataInsert(int m,STU* head);                          //增加学生信息
void DataSearch(int x,int m,STU* head);                    //根据学号查找信息
void DataReset(int m,STU* head);                           //根据学号更改信息
void DataDelete(STU* head);                                //根据学号删除信息
void DataSort1(STU* head);                                 //根据学号排序
void DataSort2(STU* head);                                 //按总分排序
void Write_file(int m,STU* head);                          //写入文件操作
void Read_file(int* n,int* m,STU* head);                   //读入文件操作
void DataProduct(int m,STU* head);                         //信息处理操作
void DataCount(int n,int m,STU*head);                      //成绩分析操作