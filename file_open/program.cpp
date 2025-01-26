#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
typedef struct person
{
    char accountnum[20];
    char name[20];
    int rest;
    char idnum[18];
    char workplace[20];
    char phonenum[11];
    char homeaddres[20];
}account;

void in();
void out();
void check();
void remove();
void insert();
void save();
void load();

int count=0;
account accounts[max];

int main()
{
    int choice;
    while(1)
    {
        printf("1.输入记录\n");
        printf("2.输出记录\n");
        printf("3.查询记录\n");
        printf("4.删除记录\n");
        printf("5.插入记录\n");
        printf("6.保存\n");
        printf("7.加载\n");
        printf("0.退出\n");
        printf("请输入你的选项:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:in();break;
            case 2:out();break;
            case 3:check();break;
            case 4:remove();break;
            case 5:insert();break;
            case 6:save();break;
            case 7:load();break;
            case 0:exit(0);
            default:printf("输入错误!请从0~7中重新输入");break;
        };
    };
    return 0;
}
//输入记录
void in()
{
    if(count<max)
    {
    account newaccount;
    printf("请输入你的账号:");
    scanf("%s",newaccount.accountnum);
    printf("请输入你的姓名:");
    scanf("%s",newaccount.name);
    printf("请输入你的余额:");
    scanf("%d",&newaccount.rest);
    printf("请输入你的身份证号码:");
    scanf("%s",newaccount.idnum);
    printf("请输入你的单位:");
    scanf("%s",newaccount.workplace);
    printf("请输入你的电话号码:");
    scanf("%s",newaccount.phonenum);
    printf("请输入你的地址:");
    scanf("%s",newaccount.homeaddres);
    accounts[count]=newaccount;
    count++;
    printf("记录输入成功!\n");
    }
    else
        printf("储存已满！");
}
//输出记录
void out()
{
    for(int i=0;i<count;i++)
    {
    printf("你的账号:%s\n",accounts[i].accountnum);
    printf("你的姓名:%s\n",accounts[i].name);
    printf("你的余额:%d\n",accounts[i].rest);
    printf("你的身份证号码:%s\n",accounts[i].idnum);
    printf("你的单位:%s\n",accounts[i].workplace);
    printf("你的电话号码:%s\n",accounts[i].phonenum);
    printf("你的地址:%s\n\n",accounts[i].homeaddres);
    }
}
//查询记录
void check()
{
    char searchaccount[20];
    printf("请输入要查找的账号:");
    scanf("%s",searchaccount);
    for(int i=0;i<count;i++)
    {
        if(strcmp(searchaccount,accounts[i].accountnum)==0)
        {
            printf("你的账号:%s\n",accounts[i].accountnum);
            printf("你的姓名:%s\n",accounts[i].name);
            printf("你的余额:%d\n",accounts[i].rest);
            printf("你的身份证号码:%s\n",accounts[i].idnum);
            printf("你的单位:%s\n",accounts[i].workplace);
            printf("你的电话号码:%s\n",accounts[i].phonenum);
            printf("你的地址:%s\n",accounts[i].homeaddres);
            return;
        }
    }
    printf("查找失败!\n");
}
//删除记录
void remove()
{
    char removeaccount[20];
    printf("请输入要删除的账号:");
    scanf("%s",removeaccount);
    for(int i=0;i<count;i++)
    {
        if(strcmp(removeaccount,accounts[i].accountnum)==0)
        {
            for(int j=i;j<count-1;j++)
            {
                accounts[j]=accounts[j+1];
            }
            count--;
            printf("删除成功!\n");
            return;
        }
    }
    printf("删除失败!未找到要删除的账号!\n");
}
//插入记录
void insert()
{
    if(count<max)
    {
    int insertcount;
    account insertaccounts;
    printf("请输入你要插入的位置/次数(从零开始):");
    scanf("%d",&insertcount);
    if(insertcount>count)
    {
        printf("输入次数过大，请重新输入!");
        return;
    }
    printf("请输入你的账号:");
    scanf("%s",insertaccounts.accountnum);
    printf("请输入你的姓名:");
    scanf("%s",insertaccounts.name);
    printf("请输入你的余额:");
    scanf("%d",&insertaccounts.rest);
    printf("请输入你的身份证号码:");
    scanf("%s",insertaccounts.idnum);
    printf("请输入你的单位:");
    scanf("%s",insertaccounts.workplace);
    printf("请输入你的电话号码:");
    scanf("%s",insertaccounts.phonenum);
    printf("请输入你的地址:");
    scanf("%s",insertaccounts.homeaddres);
        for(int i=count;i>insertcount;i--)
    {
        accounts[i]=accounts[i-1];
    }
    accounts[insertcount]=insertaccounts;
    count++;
    printf("插入成功!\n");
    }
    else
        printf("储存已满！");
}
//保存记录
void save()
{
    FILE* fp=fopen("accounts.txt","w");
    if(fp==NULL)
    {
        perror("打开文件失败!");
        return;
    }
    for(int i=0;i<count;i++)
    {
        fprintf(fp,"%s,%s,%d,%s,%s,%s\n",accounts[i].accountnum,accounts[i].name,accounts[i].rest,
        accounts[i].idnum,accounts[i].workplace,accounts[i].phonenum,accounts[i].homeaddres);
    }
    fclose(fp);
    fp==NULL;
    printf("记录已保存到accounts.txt\n");
}
//加载记录
void load()
{
    FILE* fp=fopen("accounts.txt","r");
    if(fp==NULL)
    {
        perror("打开文件失败!");
        return;
    }
    for(int i=0;i<count;i++)
    {
        fscanf(fp,"%s%s%d%s%s%s",accounts[i].accountnum,accounts[i].name,&(accounts[i].rest),
        accounts[i].idnum,accounts[i].workplace,accounts[i].phonenum,accounts[i].homeaddres);
    }
    fclose(fp);
    fp=NULL;
    for(int i=0;i<count;i++)
    {
    printf("你的账号:%s\n",accounts[i].accountnum);
    printf("你的姓名:%s\n",accounts[i].name);
    printf("你的余额:%d\n",accounts[i].rest);
    printf("你的身份证号码:%s\n",accounts[i].idnum);
    printf("你的单位:%s\n",accounts[i].workplace);
    printf("你的电话号码:%s\n",accounts[i].phonenum);
    printf("你的地址:%s\n\n",accounts[i].homeaddres);
    }
    printf("加载成功!\n");
}