#include <stdio.h>
#include <stdlib.h>

//����һ�����֣�����ܹ���ɵ����������С������������012334��
//��������Ϊ433210
//��С��Ϊ12334�� 

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
    printf("��Ҫ���뼸������\n");
    scanf("%d",&n);
    int a[n];
    printf("������������n���Ǹ�����\n");
    for(i=0;i<n;i++){
    	scanf("%d",(a+i));
//    	scanf("%d",&a[i]);
	}
	bubbleSort(a,n);//����
	printf("������ֵ:");
	if(a[n-1] == 0) printf("0");
	else{
    	for(i=n-1;i>=0;i--){
    	    printf("%d",a[i]);
		} 		
	}
	printf("\n");
    printf("�����Сֵ:");
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


