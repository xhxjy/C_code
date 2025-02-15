// #include<stdio.h>
// void print(int a)
// {
//     if(a > 9)
//     {
//         print(a / 10);
//     }
//     printf("%d ", a % 10);
// }
// //把问题拆解为下面这几个步骤
// //print(1234)
// //print(123) 4
// //print(12) 3 4
// //print(1) 2 3 4


// int main()
// {
//     int a = 1234;
//     print(a);
//     return 0;
// }
// #include<stdio.h>
// int my_strlen(char* str)
// {
//     if(*str != '\0')
//         return 1 + my_strlen(str + 1);
//     else
//         return 0;
// }
// int main()
// {
//     char arr[] = "ixhxjy";
//     printf("%d ", my_strlen(arr));
//     return 0;
// }
// //求n的阶层
// #include<stdio.h>
// int fact(int n)
// {
//     if(n == 1)
//         return 1;
//     else
//         return n * fact(n - 1);
// }
// int main()
// {
//     int n = 5;
//     printf("%d\n", fact(n));
//     return 0;
// }
//求第n个斐波那契数
// #include<stdio.h>
// int count = 0;
// int fib(int n)
// {
//     if (n == 3)
//         count++;
//     if(n == 1||n == 2)
//         return 1;
//     else
//         return fib(n - 1) + fib(n - 2);
// }
// int main()
// {
//     int num = 0;
//     scanf("%d", &num);
//     printf("%d\n", fib(num));
//     printf("%d\n", count);
//     return 0;
// }
// #include<stdio.h>
// int fib(int n)
// {
//     int a = 1, b = 1, c = 1;
//     while(n>2)
//     {
//         c=a+b;
//         a=b;
//         b=c;
//         n--;
//     }
//     return c;
// }
// int main()
// {
//     int n = 0;
//     scanf("%d", &n);
//     printf("%d\n", fib(n));
//     return 0;
// }
#include<stdio.h>
int main()
{
    int a = 2, b = 5, c = 0;
    c = a;
    a = b;
    b = c;
    printf("%d,%d,%d\n", a, b, c);
    return 0;
}
// #include<stdio.h>
// int main()
// {
//     int a[20] = {1, 1},i=0;
//     for (i = 2; i < 20; i++)
//     {
//         a[i] = a[i - 1] + a[i - 2];
//     }
//     printf("%d\n", a[19]);
//     return 0;
// }