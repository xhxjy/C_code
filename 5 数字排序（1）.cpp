#include<stdio.h>
int main(){
	int a[6],i,j,t;
    for(i=0;i<6;i++){
		scanf("%d",&a[i]);
	}

	for(i=0;i<6;i++){
		for(j=i+1;j<6;j++){
			if(a[i]>a[j]){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			}
		}
	}


    for(i=0;i<6;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}