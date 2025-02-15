// #include<stdio.h>
// int main()
// {
//     char password[20] = {0};
//     scanf("%s",password);

//     //用来清理缓冲区
//     //读取\n(循环里面什么都不用做)
//     int ch = 0;//int---getchar()的返回值是int类型
//     while((ch=getchar())!='\n')
//     {
//         ;
//     }

//     char ret = 0;
//     if('y'==(ret=getchar()))
//     {
//         printf("yes\n");
//     }
//     else{
//         printf("no\n");
//     }
//     return 0;
// }
#include<stdio.h>
int main()
{
    int ch = 0;               // 写成char ch='\0';也可以
    while((ch=getchar())!=EOF)//说明ch读到了一个正常的字符
    {
        if(ch<'0'||ch>'9')
        {
            continue;
        }
        putchar(ch);
    }
    return 0;
}
// #include<stdio.h>
// int main()
// {
//     int k = 0;
//     scanf("%d",&k);
//     switch(k)
//     {
//         case 1:
//         case 2:
//         case 3:
//         case 4:
//         case 5:
//             printf("workday\n");
//             break;
//         case 6:
//         case 7:
//             printf("workend\n");
//             break;
//         default:
//             printf("输入错误！请重新在1~7之间输入");
//             break;
//     }
//     return 0;
// }
//判断奇数
// #include<stdio.h>
// void odd(int number)
// {
//     if(number%2 == 1)
//     {
//         printf("%d ",number);
//     }
// }
// int main()
// {
//     int i = 10;
//     for (i = 1;i<100;i++)
//     {
//         odd(i);
//     }
//     printf("\n");
//     return 0;
// }
// #include<stdio.h>
// int main()
// {
//     int ch = 0;
//     while((ch=getchar()) != EOF)
//         putchar(ch);
//     return 0;
// }
// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// int main()
// {
//     char input[20] = {0};
//     system("shutdown -s -t 60");
//     while(1)
//     {
//         printf("请注意！你的电脑将在一分钟后关机！请输入：我是猪，来取消关机:\n");k
//         scanf("%s",input);
//         if(0==strcmp(input,"我是猪"))
//         {
//             system("shutdown -a");
//             break;
//         }
//     }
//     return 0;
// }
// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// int main()
// {
//     //先定义正确的密码
//     char right_password[]="ixhxjy1314";
//     char password[16]={0};
//     printf("请输入8~16位数字与字母组合的密码:\n");
//     gets(password);
//     //记录输入密码的次数
//     int count=1;
//     //上面输入了一次，所以是1

//     //法一（while的形式）
//     while(count<3)
//     {
//         if(strcmp(right_password,password)==0)
//         {
//             printf("登录成功！\n");
//             break;
//         }
//         else
//         {
//             printf("输入错误，再输一次\n");
//             printf("请输入8~16位数字与字母组合的密码:\n");
//             gets(password);
//             count++;
//         }
//     }

//     // //法二（for循环，推荐使用，因为已知循环次数）
//     // int count=0;
//     // for(count =0;count<3;count++)
//     // {
//     //     printf("请输入8~16位数字与字母组合的密码:\n");
//     //     gets(password);
//     //     if(strcmp(right_password,password)==0)
//     //     {
//     //         printf("登录成功！\n");
//     //         break;
//     //     }
//     //     else 
//     //     {
//     //         printf("输入错误，再输一次\n");
//     //     }
//     // }

//     if(3 == count)
//     {
//         exit(0);
//     }
//     return 0;
// }