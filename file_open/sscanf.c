#include<stdio.h>
typedef struct s{
    char name[20];
    int age;
    float height;
}person;
int main()
{
    person iu={"金鱼",24,50.5};
    person oi={0};
    char buffer[200]={0};
//将格式化数据转换成字符串
    sprintf(buffer,"%s %d %f",iu.name,iu.age,iu.height);
    printf("字符串:%s\n",buffer);

    sscanf(buffer,"%s %d %f",oi.name,&(oi.age),&(oi.height));
    printf("格式化:%s,%d,%f\n",oi.name,oi.age,oi.height);
    return 0;
}