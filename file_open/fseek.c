#include<stdio.h>
int main()
{
    FILE* pf=fopen("iu.txt","r");
    if(pf==NULL)
    {
        perror("打开文件失败!");
        return 0;
    }
    char ch;
    fseek(pf,2,SEEK_SET);
    ch=fgetc(pf);
    printf("%c\n",ch);
    printf("%d\n",ftell(pf));

    fseek(pf,-1,SEEK_CUR);
    ch=fgetc(pf);
    printf("%c\n",ch);

    fseek(pf,-2,SEEK_END);
    ch=fgetc(pf);
    printf("%c\n",ch);

    fseek(pf,-2,SEEK_CUR);
    ch=fgetc(pf);
    printf("%c\n",ch);

    rewind(pf);
    ch=fgetc(pf);
    printf("%c\n",ch);
    fclose(pf);
    pf=NULL;
    return 0;
}