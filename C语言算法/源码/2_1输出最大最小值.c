#include <stdio.h>
#include <stdlib.h>

//输入一组数字，输出能够组成的最大数和最小数，例如输入012334，
//输出最大数为433210
//最小数为12334。 

void selectSort(int* a,int n){
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		} 
	}
}

void bubbleSort(int* a,int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

int main(){
    int i,n;
    printf("你要输入几个数字\n");
    scanf("%d",&n);
    int a[n];
    printf("请依次输入这n个非负整数\n");
    for(i=0;i<n;i++){
    	scanf("%d",(a+i));
//    	scanf("%d",&a[i]);
	}
	bubbleSort(a,n);//排序
	printf("输出最大值:");
	if(a[n-1] == 0) printf("0");
	else{
    	for(i=n-1;i>=0;i--){
    	    printf("%d",a[i]);
		} 		
	}
	printf("\n");
    printf("输出最小值:");
    if(a[n-1] == 0) printf("0");
    else{
		for(i=0;i<n;i++){
			while(a[i]==0) i++;
			printf("%d",a[i]);
		}    	
	}
    printf("\n");
	
	return 0;
} 


