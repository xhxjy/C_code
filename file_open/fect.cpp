#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define NULL 0

void input();
void output();
void search(); 
void Delete();
void insert();
void save();
void load();


struct ComputerPart{
    char id[20];
    char partName[50];
    float price;
    char model[20];
    char producer[50];
    char time[20];
};


ComputerPart partArr[100];
int count = 0;

int main(){
    int choice;
    while(1){
        printf("请选择操作:\n");
        printf("1. 输入数据\n");
        printf("2. 输出数据\n");
        printf("3. 查询数据\n");
        printf("4. 删除数据\n");
        printf("5. 插入数据\n");
        printf("6. 保存数据\n");
        printf("7. 加载数据\n");
		printf("8. 退出程序\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:input();  break;
			case 2:output(); break;
			case 3:search(); break;
            case 4:Delete(); break;
            case 5:insert(); break;
            case 6:save();   break;  
			case 7:load();   break; 
            case 8:exit(0);
			default:printf("------选择无效，请重新选择(1-8)------!\n");      
        }
    }
    return 0;
}


void input(){
    if(count<100){
        ComputerPart part;
        printf("请输入编号: ");
        scanf("%s",part.id);
        printf("请输入部件名: ");
        scanf("%s",part.partName);
        printf("请输入价格: ");
        scanf("%f",&part.price);
        printf("请输入型号: ");
        scanf("%s",part.model);
        printf("请输入厂商: ");
        scanf("%s",part.producer);
        printf("请输入报价时间: ");
        scanf("%s", part.time);

        partArr[count]=part;
        count++;

        printf("----------输入记录成功!----------\n");
	} 
	else{
        printf("----存储已满，无法继续输入记录!----\n");
    }
}


void output(){
    for(int i=0;i<count;i++){
        printf("编号: %s\t部件名: %s\t价格: %.2f\t型号: %s\t厂商: %s\t报价时间: %s\n",
               partArr[i].id, partArr[i].partName, partArr[i].price, partArr[i].model, partArr[i].producer, partArr[i].time);
    }
}


void search(){
    char search_id[20];
    printf("请输入要查询的编号:");
    scanf("%s",search_id);
    for(int i=0;i<count;i++){
        if(strcmp(partArr[i].id,search_id)==0){
            printf("编号: %s\t部件名: %s\t价格: %.2f\t型号: %s\t厂商: %s\t报价时间: %s\n",
                   partArr[i].id, partArr[i].partName, partArr[i].price, partArr[i].model, partArr[i].producer, partArr[i].time);
            return;
        }
    }
    printf("---------未找到此编号的记录!--------\n");
}


void Delete(){
    char delete_id[20];
    printf("请输入要删除的编号:");
    scanf("%s",delete_id);
    for(int i=0;i<count;i++){
        if(strcmp(partArr[i].id,delete_id)==0){
            for(int j=i;j<count-1;j++) {
                partArr[j] = partArr[j+1];
            }
            count--;
            printf("--------删除记录成功!--------\n");
            return;
        }
    }
    printf("-----未找到该编号的记录，删除失败!-----\n");
}


void insert(){
    if (count<100){
        int id;
        printf("输入插入点的数据编号(从1开始计数): ");
        scanf("%d",&id);
        if (id<=0 || id>count) {
            printf("--------位置无效，请重新操作！--------");
			return;
        }
		ComputerPart part;
		printf("请输入编号: ");
		scanf("%s",part.id);
		printf("请输入部件名: ");
		scanf("%s",part.partName);
		printf("请输入价格: ");
		scanf("%f",&part.price);
		printf("请输入型号: ");
		scanf("%s",part.model);
		printf("请输入厂商: ");
		scanf("%s", part.producer);
		printf("请输入报价时间: ");
		scanf("%s",part.time);

        for(int i=count;i>id;i--){
            partArr[i]=partArr[i-1];
        }
        partArr[id-1]=part;
        count++;

        printf("---------插入成功!--------\n");
    }
	else{
        printf("-------存储已满，插入失败!------\n");
	}
}


void save(){
    FILE *fp;
	fp=fopen("电脑报价数据.txt","wb");
    if(fp==NULL){
        printf("保存失败!\n");
        return;
    }
    for(int i=0;i<count;i++){
        fwrite(&partArr[i],sizeof(struct ComputerPart),1,fp);//partArr[i].id, partArr[i].partName, partArr[i].price, partArr[i].model, partArr[i].producer, partArr[i].time
    }
    fclose(fp);
    fp==NULL;
    printf("-------保存成功!-------\n");
}


void load(){
	FILE *fp;
	int i=0;
	fp=fopen("电脑报价数据.txt","rb");
    if (fp==NULL) {
        printf("------加载失败!------\n");
        return;
    }	
		while(!feof(fp)){
			fread(&partArr[i],sizeof(struct ComputerPart),1,fp);
			i++;
		}
		printf("------加载成功!------\n");
		fclose(fp);
		count=(--i);
	
}