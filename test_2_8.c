// //二分法
// #include<stdio.h>
// int binary_search(int a[],int num,int sz)
// {
//     int min = 0, max = sz-1, mid = 0;
//     while(min<=max)
//     {
//         mid = (min + max) / 2;
//         if(num>a[mid])
//         {
//             min = mid + 1;
//         }
//         else if(num<a[mid])
//         {
//             max = mid - 1;
//         }
//         else
//         {
//             return mid;//return后直接就结束了，不需要break
//         }
//     }
//     //由于子程序的特殊性,假如找到了会直接结束程序，因此这里也无需做判断，直接返回即可
//     return -1;
//     //返回值不可设为0，因为数组的下标可能为0，最好设置为负数
// }
// //找不到
// int main()
// {
//     int a[] = {1, 3, 5, 8, 9};
//     int num = 0;
//     int sz = sizeof(a) / sizeof(a[0]);
//     printf("请输入你要查找的数字:");
//     scanf("%d", &num);
//     //将函数返回值赋给一个变量便于后面书写
//     int ret = binary_search(a, num, sz);//先写这个函数怎么用，即写出函数参数；再思考具体怎么写
//     if(-1 == ret)
//     {
//         printf("找不到！\n");
//     }
//     else
//     {
//         printf("找到了，其下标为%d\n", ret);
//     }
//     return 0;
// }
// #include<stdio.h>
// //无效
// // void swap(int a,int b)
// // {
// //     int tem=0;
// //     tem=a;
// //     a=b;
// //     b=tem;
// // }

// //有效
// void swap(int* a,int* b)
// {
//     int tem=0;
//     tem=(*a);
//     (*a)=(*b);
//     (*b)=tem;
// }

// int main()
// {
//     int a=10,b=20;
//     swap(&a,&b);
//     printf("a=%d,b=%d",a,b);
//     return 0;
// }
#include<stdio.h>
int main()
{
    printf("%d",printf("%d",printf("%d",43)));
    return 0;
}
// #include<stdio.h>
// int add(int* num)
// {
//     return ++(*num);
// }
// int main()
// {
//     int num = 0;
//     int i = 0;
//     for (i = 0; i < 5;i++)
//     {
//         printf("%d ", add(&num));
//     }
//     return 0;
// }
// #include <stdio.h>
// int main()
// {
//     printf("%d", printf("%d", printf("%d", 43)));
//     return 0;
// }
// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char str[10] = "ixh";
//     int ret = strlen(strcat(str, "xjy"));
//     printf("%d\n", ret);
//     return 0;
// }
//素数
// #include<stdio.h>
// #include<math.h>
// int isprime(int num)
// {
//     int i = 0;
//     for (i = 2; i <= sqrt(num);i++)
//     {
//         if(num%i == 0)
//         {
//             return 0;
//         }
//     }
//     return 1;
// }
// //是素数就返回1，不是则返回0
// int main()
// {
//     int i = 0;
//     //判断100~200的素数，由于素数一定是奇数，所以直接从101开始判断，且递加2
//     for (i = 101; i <= 200; i+=2)
//     {
//         //返回值的构造有技巧，返回1时，条件为真则执行
//         if(isprime(i))
//         {
//             printf("%d ", i);
//         }
//     }
//     return 0;
// }