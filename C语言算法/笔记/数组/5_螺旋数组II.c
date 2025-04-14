#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;//二维数组有几行 
	int** ans = (int**)malloc(sizeof(int*)*n);//分配二维数组的行指针 
	*returnColumnSizes = (int*)malloc(sizeof(int)*n);//给二维数组的每行列数分配空间 
	int i=0,j=0;
	for(i=0;i<n;i++){
		ans[i] = (int*)malloc(sizeof(int)*n);//给第n行分配n列 
		(*returnColumnSizes)[i] = n;//告诉调用者这一行有n列 
	}
	int startX = 0,startY = 0;//定义每循环一圈的起始位置 
	int offset = 1;//控制赋值时的边的长度
	int mid  = n/2;//如果n是奇数那么需要将中间值赋值为n/2,如果是偶数则不必 
	int loop = n/2;//循环的次数 
	int count = 1;//给每个数组位置赋值 
	while(loop){
		i = startX;//行 
		j = startY;//列 
		//上 
		for(;j<n-offset;j++){
		   ans[i][j] = count++; 	
		}
		//右 
		for(;i<n-offset;i++){
			ans[i][j] = count++;
		}
		//下
		for(;j>startY;j--){
			ans[i][j] = count++; 
		}
		//左
		for(;i>startX;i--){
			ans[i][j] = count++;
		}
		startX++;
		startY++;
		offset++;//控制每一圈里每一条边遍历的长度
		loop--;
	}
	if(n%2) ans[mid][mid] = count;
	return ans;  
}

int main(){
	int n;
	printf("请输入一个数:\n");
	scanf("%d",&n);
	int* returnSize;
	int** returnColumnSizes;
	int** ans = generateMatrix(n,&returnSize,&returnColumnSizes);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%3d ",ans[i][j]);
		}
		printf("\n");
	}
	free(returnSize);
	free(returnColumnSizes);
	free(ans);
	return 0;
} 
