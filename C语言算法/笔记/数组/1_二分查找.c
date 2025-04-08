#include <stdio.h>

//闭区间 [left,right]
int BinarySearch_1(int a[],int len,int target){
	int left = 0;
	int right = len - 1;
	int mid;
	while(left <= right) {
	   	mid = left + ((right - left)/2);
	   	if(a[mid] < target) {
	   		left = mid + 1; 
		} else if(a[mid] > target) {
			right = mid - 1;
		} else {
			return mid;
		}
	}
	return -1;
}

//左闭右开 [left,right)
int BinarySearch_2(int a[],int len,int target){
    int left = 0;
    int right = len;
	int mid;
    while(left<right){
    	mid = left + ((right - left)/2);
    	if(a[mid] < target){
    		left = mid + 1;
		} else if(a[mid] > target){
			right = mid;
		} else {
			return mid;
		}
	}
	return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,10};
	int n,re;
	printf("请输入要查找的数字:\n");
	scanf("%d",&n);
	re = BinarySearch_2(arr,sizeof(arr)/sizeof(arr[0]),n);
	if(re >= 0) printf("%d所在下标为%d\n",n,re);
	else printf("未找到该数字...\n");    	
	return 0;
} 

