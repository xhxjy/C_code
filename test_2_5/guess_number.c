#include<stdio.h>
#include<stdlib.h>//srand
#include<time.h>//time
void menu()
{
    printf("******************************\n");
    printf("***********1.play*************\n");
    printf("***********0.exit*************\n");
    printf("******************************\n");
}
//写代码，养成写一部分代码，测试一部分代码的习惯
//先把大框架写好，检测一下有没有问题，再往细处写
void game()
{    int guess = 0;
    //1.生成随机数
    int num=rand()%100+1;//生成随机数的函数
    //rand()的数字范围最大是0~32767
    //rand()%100的余数范围一定是0~99，所以num的范围是1~100

    //printf("%d\n",num);

    //2.猜数字
    while(1)
    {
        printf("请猜数字：");   
        scanf("%d", &guess);
        if(guess>num)
        {
            printf("猜大了！再猜一次\n");
        }
        else if(guess<num)
        {
            printf("猜小了！再猜一次\n");
        }
        else
        {
            printf("恭喜你，猜对了！\n");
            break;
        }
    }
}
int main()
{
    //返回时间戳，防止出现返回的随机数相同的情况（生成随机数的一个步骤）
    srand((unsigned int)time(NULL));
    int choice = 0;
    do
    {
        menu();
        printf("请输入你的选项：");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏!\n");
            exit(0);
            break;
        default:
            printf("输入错误，重新输入！\n");
            break;
        }
    } while (choice);
    return 0;
}