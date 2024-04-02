#include"student1.h"


void GotoXY(int x, int y)//光标定位函数
{
    HANDLE hout;
    COORD cor;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    cor.X = x;
    cor.Y = y;
    SetConsoleCursorPosition(hout, cor);
}

int Menu()//菜单界面（到时候可以写一个分级菜单）
{
    int choice;//储存选择操作 
    GotoXY(52, 1);
    printf("学生成绩管理系统（教师端）\n");
    for (int i = 0; i < 2; i++)//上边界
    {
        GotoXY(30, 3+i);
        for (int j = 0; j < 60; j++)
        {
            printf("-");
        }
    }
    /*功能菜单*/
    GotoXY(32,6);
    printf("1.输入学生成绩");
    GotoXY(32, 8);
    printf("2.输出学生成绩");
    GotoXY(32, 10);
    printf("3.增加学生信息");
    GotoXY(32, 12);
    printf("4.查找学生信息");
    GotoXY(32, 14);
    printf("5.更改学生信息");
    GotoXY(32, 16);
    printf("6.删除学生信息");
    GotoXY(32, 18);
    printf("7.学习信息排序");
    GotoXY(64, 6);
    printf("8.信息写入文件");
    GotoXY(64,8);
    printf("9. 信息读入文件");
    GotoXY(64,10);
    printf("10.信息处理");
    GotoXY(64,12);
    printf("11.学生成绩分析");
    GotoXY(64,14);
    printf("12.学生总分排名");
    GotoXY(64,16);
    printf("0.退出系统");



    for (int i = 0; i < 2; i++)//下边界
    {
        GotoXY(30, 20 + i);
        for (int j = 0; j < 60; j++)
        {
            printf("-");
        }
    }
    GotoXY(29, 23);
    printf("选择操作0—16：|    |\b\b\b\b");//退格操作：\b
    scanf("%d", &choice);
    return choice;
}

int Menu1()      //学生菜单界面
{
    int choice;//储存选择操作 
    GotoXY(52, 1);
    printf("学生成绩管理系统（学生端）\n");
    GotoXY(40,20);
    printf("成绩查询1/退出程序0：|   |\b\b");
    scanf("%d",&choice);
    return choice;
}




void DataInput(int* n,int* m,STU* head)//信息输入函数
{
    STU* p, * q;
    p = head;
    GotoXY(40, 6);
    printf("输入学生人数（n<%d）", STU_NUM);
    scanf("%d", n);
    GotoXY(40, 8);
    printf("输入课程数（m<%d）", COURSE_NUM);
    scanf("%d", m);
    for (int i = 0; i < 2; i++)
    {
        GotoXY(35, 9 + i);
        for (int j = 0; j < 55; j++)
        {
            printf("-");
        }
    }
    GotoXY(40, 11);
    printf("输入学生学号、姓名以及各课成绩：\n");
    for (int i = 0; i < *n; i++)
    {
        q = (STU*)malloc(sizeof(STU));
        q->next = NULL;
        GotoXY(40, 12 + i);
        printf("输入第%d个学生信息：\t", i + 1);
        scanf("%ld%s", &q->num, q->name);
        for (int j = 0; j < *m; j++)
        {
            scanf("%f", &q->score[j]);
        }
        p->next = q;
        p = p->next;

    }
}

void DataOutput(int* m,STU * head)//信息输出函数
{
    STU* p;
    p = head->next;
    printf("学号\t\t姓名\t\t");
    for (int i = 0; i < *m; i++)
    {
        printf("课程%d\t\t", i + 1);
    }
    printf("总分\t\t平均分\n");
    while(p!=NULL)
    {
        printf("%-16ld%-16s", p->num, p->name);
        for (int i = 0; i < *m; i++)
        {
            printf("%-16.1lf", p->score[i]);
        }
        printf("%-16.1lf%-16.1lf\n", p->sum, p->aver);
        p = p->next;
    }
}

void DataInsert(int m,STU* head)//信息增加函数
{
    int x;
    STU*p,*q;
    if(head==NULL)
    {
        printf("head为空");
        return ;
    }
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    GotoXY(40,6);
    printf("增加的学生信息数量:");
    scanf("%d",&x);
    GotoXY(40, 8);
    printf("输入新增学生学号、姓名以及各课成绩：\n");
    for (int i = 0; i < x; i++)
    {
        q = (STU*)malloc(sizeof(STU));
        q->next = NULL;
        GotoXY(40, 10 + i);
        printf("输入第%d个学生信息：\t", i + 1);
        scanf("%ld%s", &q->num, q->name);
        for (int j = 0; j < m; j++)
        {
            scanf("%f", &q->score[j]);
        }
        p->next = q;
        p = p->next;

    }
}

void DataSearch(int x,int m,STU* head)      //信息查找函数（可以增添界面内重复查找的功能）
{
    STU *p;
    p=head;
    while(p!=NULL)
    {
        if(p->num==x)
        {
            GotoXY(10,8);
            printf("该学生的姓名、各科成绩、总分，平均分为,排名为：\n");
            printf("%-16s", p->name);
            for (int i = 0; i < m; i++)
            {
            printf("%-16.1lf", p->score[i]);
            }
            printf("%-16.1lf%-16.1lf%-16d\n", p->sum, p->aver,p->rank);
            break;
        }
        else{p = p->next;}
    }
    if(p==NULL)
    {
        GotoXY(40,14);
        printf("查无此人！\n");
    }
}

void DataReset(int m,STU* head)        //信息修改函数
{
    int x;

    STU *p=head,*q;
    q=(STU*)malloc(sizeof(STU));
    q->next=NULL;
    
    GotoXY(40,6);
    printf("需要修改信息的学生的学号：");
    scanf("%d",&x);
    while(p->next!=NULL)
    {
        if(p->next->num==x)
        {
            GotoXY(5,8);
            q->num=p->next->num;
            printf("更改后该学生的姓名、各科成绩为：");
            scanf("%s", q->name);
            for (int j = 0; j < m; j++)
            {
                scanf("%f", &q->score[j]);
            }

            q->next=p->next->next;//直接将原结点扔掉
            free(p->next);
            p->next=q;
            p=p->next;
            GotoXY(40,10);
            printf("修改成功！\n");
            system("pause");
            break;
        }
        else{p = p->next;}
    }
    if(p->next==NULL)
    {
        GotoXY(40,14);
        printf("查无此人\n");
        system("pause");
    }
}

void DataDelete(STU* head)             //根据学号删除信息
{
    int x;
    GotoXY(40,6);
    printf("需要删除的学生的学号：");
    scanf("%d",&x);
    STU *p=head;
    while(p->next!=NULL)
    {
        if(p->next->num==x)
        {
            p->next=p->next->next;
            GotoXY(40,10);
            printf("删除完成\n");
            system("pause");
            break;
        }
        else{p=p->next;}
    }
    if(p->next==NULL)
    {
        GotoXY(40,14);
        printf("查无此人!\n");
        system("pause");
    }
}

void DataSort1(STU* head)                //按学号升序排序
{
    int n=0;
    STU *m,*p,*q;
    m=head;
    while(m->next!=NULL){m=m->next;n++;}
    for(int i=0;i<n;i++)
    {
        p=head;
        q=p->next;
    while(q->next!=NULL)
    {

        if((p->next->num)>(q->next->num))//相邻结点交换位置
        {
            p->next=q->next;
            q->next=q->next->next;
            p->next->next=q;
            p=p->next;
        }
        else
        {
            p=p->next;
            q=q->next;
        }
    }
    }
    GotoXY(40,14);
    printf("按学号排序成功！\n");
    system("pause");     
}

void DataSort2(STU* head)               //按总分排序,并产生排名
{
    int n=0,x=1;
    STU *m,*p,*q,*y;
    m=head;
    y=head;
    while(m->next!=NULL){m=m->next;n++;}
    for(int i=0;i<n;i++)
    {
        p=head;
        q=p->next;
    while(q->next!=NULL)
    {

        if((p->next->sum)<(q->next->sum))//相邻结点交换位置
        {
            p->next=q->next;
            q->next=q->next->next;
            p->next->next=q;
            p=p->next;
        }
        else
        {
            p=p->next;
            q=q->next;
        }
    }
    while(y->next!=NULL)            //产生排名
    {
        y->next->rank=x;
        x++;
        y=y->next;
    }
    }
    GotoXY(40,14);
    printf("按学号排序成功！\n");
    system("pause");     
}









void Write_file(int m,STU* head)              //信息写入文件
{
    STU *p;
    p=head->next;
    FILE *q;
    q=fopen("Student_Inf1.txt","w");
    fprintf(q,"学号\t\t姓名\t\t");
    for (int i = 0; i < m; i++)
    {
        fprintf(q,"课程%d\t\t", i + 1);
    }
    fprintf(q,"总分\t\t平均分\n");
    while(p!=NULL)
    {
        fprintf(q,"%-16ld%-16s", p->num, p->name);
        for (int i = 0; i < m; i++)
        {
            fprintf(q,"%-16.1lf", p->score[i]);
        }
        fprintf(q,"%-16.1lf%-16.1lf\n", p->sum, p->aver);
        p = p->next;
    }
    fclose(q);
    GotoXY(40,14);
    printf("写入成功！\n");
    system("pause");
}

void Read_file(int  *n,int *m,STU* head)
{
    STU *p,*q;
    p=head;
    FILE *f; 
    f=fopen("Student_Inf2.txt","r");
    fscanf(f,"%d",n);
    fscanf(f,"%d",m);
    for (int i = 0; i < *n; i++)
    {
        q = (STU*)malloc(sizeof(STU));
        q->next = NULL;
        fscanf(f,"%ld%s", &q->num, q->name);
        for (int j = 0; j < *m; j++)
        {
            fscanf(f,"%f", &q->score[j]);
        }
        p->next = q;
        p = p->next;
    }
    fclose(f);
    GotoXY(40,14);
    printf("读入成功！\n");
    system("pause");
}

void DataProduct(int m,STU* head)      //数据处理
{
    STU *p;
    p=head->next;
    while(p!=NULL)
    {
        p->sum=0;
        for(int i=0;i<m;i++)
        {
            p->sum+=p->score[i];
        }
        p->aver=(p->sum)/m;
        p=p->next;
    }
    GotoXY(40,14);
    printf("已计算总分和平均分\n");
    system("pause");
}

void DataCount(int n,int m,STU* head) //数据分析（计算每科平均分）
{
    STU *p;
    p=head->next;
    float eva[m];
    float t;
    for(int i=0;i<m;i++)
    {
        t=0;
        while(p!=NULL)
        {
            t+=p->score[i];
            p=p->next;
        }   
        eva[i]=t/n;    
    }
    for(int j=0;j<m;j++)
    {
        GotoXY(10,3+j*2);
        printf("班级课程%d平均分为：%-16f\n",j+1,eva[j]);
    }
    system("pause");
}

int MenuLoad(int *x,int* num,USER* users)                      //登录/注册界面
{
    int ch;
    GotoXY(50,10);
    printf(" 用户登陆界面\n");
    GotoXY(20,20);
    printf("注册0/登录1/退出2 ：|   |\b\b");
    scanf("%d",&ch);
    USER temp;
    FILE *p;
    p=fopen("User.txt","r+");
    fprintf(p,"职位\t\t学号\t\t用户名\t\t密码\t\t\n");
    fclose(p);
    system("cls");
    switch(ch)
    {
        case 0:
            GotoXY(30,5);
            printf("输入用户职位(student/teacher)：");
            scanf("%s",(users[*num]).position);
            if(!(strcmp(users[*num].position,"teacher")==0||strcmp(users[*num].position,"student")==0))
            {
                return 6;       //输入职称出错
            }
            GotoXY(30,10);
            printf("学生输入学号，教师输入0：");
            scanf("%d",&(users[*num].num));
            *x=users[*num].num;             //将学号传递到主函数
            GotoXY(30,15);
            printf("输入用户名：");
            scanf("%s",(users[*num]).name);
            GotoXY(30,20);
            printf("输入用户密码：");
            scanf("%s",(users[*num].password));
            p=fopen("User.txt","a");
            fprintf(p,"%-16s%-16d%-16s%-16s",users[*num].position,users[*num].num,users[*num].name,users[*num].password);
            fprintf(p,"\n");
            (*num)++;
            fclose(p);
            return 0;           //注册成功
            break;
        case 1:
            GotoXY(30,10);
            printf("输入用户职位：");
            scanf("%s",temp.position);
            GotoXY(30,15);
            printf("输入用户名：");
            scanf("%s",temp.name);
            GotoXY(30,20);
            printf("输入用户密码：");
            scanf("%s",temp.password);
            for(int i=0;i<*num;i++)
            {
                if(strcmp(users[i].name,temp.name)==0&&strcmp(users[i].password,temp.password)==0\
                &&strcmp(users[i].position,temp.position)==0)           //登录成功
                {
                    if(temp.position[0]=='t'){return 1;}        //权限为老师
                    else if(temp.position[0]=='s'){return 5;}   //权限为学生
                }
            }
            return 2;//登录失败（账号or密码不对）
            break;
        case 2:
            return 4;//退出程序
        default:
            return 3;//登录界面输入出错
    }
}