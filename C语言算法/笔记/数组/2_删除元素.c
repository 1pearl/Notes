#include <stdio.h>

//暴力 
int removeElement_1(int a[],int len,int target){
	int i,j;
	for(i=0;i<len;i++){
		if(a[i] == target){
			for(j=i+1;j<len;j++){
			    a[j-1] = a[j];
			}
			i--;
			len--;						
		}
	}
	return len;
}

//快慢指针
int  removeElement_2(int a[],int len,int target){
    int slowPoint=0,fastPoint=0;
    for(fastPoint = 0;fastPoint<len;fastPoint++){
    	if(a[fastPoint] != target){
    		a[slowPoint++] = a[fastPoint];
		}
	}
	return slowPoint;
}

int main(){
	int arr[] = {2,2,3,3,1,2,3,5,10};
	int n;
	printf("请输入你要删除的元素:\n");
	scanf("%d",&n);
	int re =  removeElement_1(arr,sizeof(arr)/sizeof(arr[0]),n);
	printf("删除了%d后的数组长度为%d\n",n,re);
	return 0;
} 
