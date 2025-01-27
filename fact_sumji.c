#include<stdio.h>
int fact(int n)
{
    int t=1,i;
    for(i=1;i<=n;i++){
        t*=i;
    }
    return t;
}
int main()
{
    int sum=0,i;
    for(i=1;i<=5;i+=2)
        sum+=fact(i);
    printf("%d\n",sum);
    return 0;
}