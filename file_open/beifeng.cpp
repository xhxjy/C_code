保存记录
void save()
{
    FILE* fp=fopen("accounts.txt","w");
    if(fp==NULL)
    {
        perror("打开文件失败!");
        return;
    }
    for(int i=0;i<count;i++)
    {
        fwrite(&(accounts[i]),sizeof(account),count,fp);
    fclose(fp);
    }
    printf("记录已保存到accounts.txt\n");
}