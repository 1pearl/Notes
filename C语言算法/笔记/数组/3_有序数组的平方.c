#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;//返回的数组大小就是原数组的大小
    int l = 0;
	int r = numsSize - 1; 
	int i;
	int* ans = (int*)malloc(numsSize*sizeof(int));
	for(i=numsSize-1; i>=0; i--){
        int lSquare = nums[l]*nums[l];
		int rSquare = nums[r]*nums[r];
		if(lSquare < rSquare) {
			ans[i] = rSquare;
			r--;
		} else {
			ans[i] = lSquare;
			l++;
		}
	}
	return ans; 
}

int main(){
    int a[] = {-9,-7,-1,0,1,2,3};
    int ans_size=0;
	int* ans = sortedSquares(a,sizeof(a)/sizeof(a[0]),&ans_size);
	int i;
	printf("%d\n",ans_size);
	for(i=0;i<ans_size;i++){
		printf("%d ",ans[i]);
	} 	
	return 0;
} 
