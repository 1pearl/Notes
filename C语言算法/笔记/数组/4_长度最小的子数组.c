#include <stdio.h>
#include <stdint.h>
//���� 
int minSubArrayLen_1(int target, int* nums, int numsSize) {
    int len = INT32_MAX;
    int i,j;
    for(i=0;i<numsSize;i++){
    	int sum = 0;
    	for(j=i;j<numsSize;j++){
    		sum += nums[j];
    		if(sum >= target){
    			int arrSubLen = j-i+1;
				len = len < arrSubLen ? len : arrSubLen;
				break; 
			}
		}
	}
	return len == INT32_MAX ? 0 : len;
}
//�������� 
int minSubArrayLen_2(int target, int* nums, int numsSize) {
	int minLen = INT32_MAX;
	int i=0,j=0;//i��Ϊ��ֹ�߽�,jΪ��ʼ�߽� 
	int sum = 0;
	for(;i<numsSize;i++){
		 sum+=nums[i];
		 while(sum>=target){
		 	int SubArrLen = i-j+1;
		 	minLen = minLen < SubArrLen ? minLen : SubArrLen;
			sum -= nums[j];
			j++;  
		 }
	}
	return minLen == INT32_MAX ? 0:minLen;
}

int main(){
	int a[] = {2,3,0,1,4,1,2,3};
	int target = 90;
	int re = minSubArrayLen_2(target,a,sizeof(a)/sizeof(a[0]));
	printf("��С�����鳤��Ϊ:%d\n",re); 
	return 0;
} 
