#include<stdio.h>
#define n 30
int main(){
    int i,arr[n];
    arr[0]=1,arr[1]=1;
    for(i=2;i<n;i++){
        arr[i]=arr[i-2]+arr[i-1];
    }
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    printf("\n");
    return 0;
}