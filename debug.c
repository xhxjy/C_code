#include<stdio.h>
int main()
{
    int i,arr[10]={0};
    for(i=0;i<10;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<10;i++)
        printf("%d ",arr[i]+1);
    return 0;
}
