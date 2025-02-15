// #include<stdio.h>
// int main()
// {
//     int i = 0;
//     for(i=0;i<10;i++)
//     {
//         printf("%d ",i);
//         i=12;//打印一次直接跳出
//         //i=5;//死循环
//     }
//     return 0;
// }
// //最大公约数
//1.辗转相除法（效率高）
#include<stdio.h>
int main()
{
    int a = 0, b = 0, r = 0;
    printf("请输入两个整数：");
    scanf("%d%d", &a, &b);
    // if(a<b)
    // {
    //     c = a;
    //     a = b;
    //     b = c;
    // }
//无需担心两者的大小问题，若a=24,b=32,a%b=24(商0，余24)，类似于1%10=1；即r=24
//之后a=32,b=24,它又自己走回来了
    
    r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    //逻辑不对
    // do
    // {
    //     r = a % b;
    //     a = b;
    //     b = r;
    // } while (r != 0);
    printf("%d\n", b);
    return 0;
}
//2.暴力求解（效率低）
// #include<stdio.h>
// int min = (a < b) ? a : b;//求两者的最小值
// while(1)
// {
//     if(a % min == 0&& b % min == 0)
//     {
//         break;
//     }
//     min--;
// }
// printf("%d", min);
////三个数排序
////1.冒泡排序
// #include<stdio.h>
// void sort(int a[],int sz)
// {
//     int i = 0, j = 0, tem = 0;
//     for (i = 0; i < sz - 1; i++)
//     {
//         for (j = 0; j < sz - i - 1; j++)
//         {
//             if(a[j]<a[j+1])
//             {
//                 tem = a[j];
//                 a[j] = a[j + 1];
//                 a[j + 1] = tem;
//             }
//         }
//     }
// }
////2.用if语句，两个两个比，分别比3次
////2.1 常规比较
// if(a>b)
// {
//     tem = a;
//     a = b;
//     b = tem;
// }
// if(....)
// if(...)
// //2.2 将交换的功能写成一个函数
// if(...)
//     swap();
// int main()
// {
//     int arr[3] = {0};
//     int i = 0;
//     for (i = 0; i < 3; i++)
//         scanf("%d", &arr[i]);
//     sort(arr, 3);
//     for (i = 0; i < 3; i++)
//         printf("%d ", arr[i]);
//     return 0;
// }