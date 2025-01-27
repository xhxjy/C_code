#include<stdio.h>
int main()
{
    int grade,score;
    printf("请输入你的成绩:");
    scanf("%d",&score);
    switch(score/10)
    {
        case 10:
        case 9:grade='A';break;
        case 8:grade='B';break;
        case 7:grade='C';break;
        case 6:grade='D';break;
        default: grade='E';
    }
    printf("你的考试等级是%c\n",grade);
    return 0;
}