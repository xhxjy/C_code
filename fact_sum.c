#include<stdio.h>
int main()
{
    int sum=0,t=1,i;
    for(i=1;i<=5;i++){
        t*=i;
        sum+=t;
    }
    printf("%d\n",sum);
    return 0;
}