#include<stdio.h>
int main(){
	char name[20]="DELHIkiafid";int length=0; char* p=name;
	for(;(*p)!='\0';length++,p++){}
	printf("length=%d\n",length);
	return 0;
}