#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;//��ά�����м��� 
	int** ans = (int**)malloc(sizeof(int*)*n);//�����ά�������ָ�� 
	*returnColumnSizes = (int*)malloc(sizeof(int)*n);//����ά�����ÿ����������ռ� 
	int i=0,j=0;
	for(i=0;i<n;i++){
		ans[i] = (int*)malloc(sizeof(int)*n);//����n�з���n�� 
		(*returnColumnSizes)[i] = n;//���ߵ�������һ����n�� 
	}
	int startX = 0,startY = 0;//����ÿѭ��һȦ����ʼλ�� 
	int offset = 1;//���Ƹ�ֵʱ�ıߵĳ���
	int mid  = n/2;//���n��������ô��Ҫ���м�ֵ��ֵΪn/2,�����ż���򲻱� 
	int loop = n/2;//ѭ���Ĵ��� 
	int count = 1;//��ÿ������λ�ø�ֵ 
	while(loop){
		i = startX;//�� 
		j = startY;//�� 
		//�� 
		for(;j<n-offset;j++){
		   ans[i][j] = count++; 	
		}
		//�� 
		for(;i<n-offset;i++){
			ans[i][j] = count++;
		}
		//��
		for(;j>startY;j--){
			ans[i][j] = count++; 
		}
		//��
		for(;i>startX;i--){
			ans[i][j] = count++;
		}
		startX++;
		startY++;
		offset++;//����ÿһȦ��ÿһ���߱����ĳ���
		loop--;
	}
	if(n%2) ans[mid][mid] = count;
	return ans;  
}

int main(){
	int n;
	printf("������һ����:\n");
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
