#include<stdio.h>
typedef struct s{
    char name[20];
    int age;
    float height;
}person;
//将格式化数据转换成字符串
int main()
{
    person iu={"金鱼",24,50.5};
    char buffer[200]={0};
    sprintf(buffer,"名字:%s,年龄:%d,体重:%f",iu.name,iu.age,iu.height);
    printf("%s\n",buffer);
    return 0;
}