// #include<stdio.h>
// int main()
// {
//     int i = 0, count = 0;
//     for (i = 1; i <= 100; i++)
//     {
//         if(9==i%10)
//             count++;
//         if(9==i/10)
//             count++;
//     }
//     printf("%d", count);
//     return 0;
// }
// //分数求和
// #include<stdio.h>
// int main()
// {
//     int i = 0;
//     float sum = 0.0f;//因为是分数，不能用int
//     for (i = 1; i <= 100; i++)
//     {
//     //法1
//         if (1 == i % 2)
//             sum += 1.0 / i;
//         else
//             sum -= 1.0 / i;

//     //法2
//     int flag = 1;
//     for (i = 1; i <= 100; i++)
//     {
//         sum += (flag * 1.0) / i;
//         flag = -flag;
//     }
//     //用flag来改变正负

//     }
//     printf("%f\n", sum);
//     return 0;
// }
// #include<stdio.h>
// int main()
// {
//     int i = 0;
//     int flag = 1;
//     float sum = 0.0f;
//     for (i = 1; i <= 100; i++)
//     {
//         sum += (flag * 1.0) / i;
//         flag = -flag;
//     }
//     printf("%f\n", sum);
//     return 0;
// }
// //九九乘法表
// #include<stdio.h>
// void excel(int n)
// {
//     int i = 0, j = 0;
//     for (i = 1; i <= n; i++)
//     {
//         for (j = 1; j <= i; j++)
//         {
//             printf("%-2d*%-2d=%-2d ", i, j, i * j);
//         }
//         printf("\n");
//     }
// }
// int main()
// {
//     int n = 0;
//     scanf("%d", &n);
//     excel(n);
//     return 0;
// }
// #include<stdio.h>
// int my_strlen(char* str)
// {
//     int count = 0;
//     while((*str)!=0)
//     {
//         count++;
//         str++;
//     }
//     return count;
// }
// int main()
// {
//     char str[] = "i xh xjy";
//     printf("%d\n", my_strlen(str));
//     return 0;
// }
// #include<stdio.h>
// int fact(int n,int k)
// {
//     if(1==k)
//         return n;
//     else
//         return n*fact(n, k - 1);
// }
// int main()
// {
//     int n = 0, k = 0;
//     scanf("%d%d", &n, &k);
//     printf("%d\n", fact(n, k));
//     return 0;
// }
//计算一个数的每位之和（递归实现）
