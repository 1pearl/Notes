#include <stdio.h>
#include <stdlib.h>

// 矩阵求和函数
void addMatrices(int A[3][3], int B[3][3], int C[3][3]) {
   int i,j;
   for(i=0;i<3;i++){
   	for(j=0;j<3;j++){
   		C[i][j] = A[i][j]+B[i][j];
	   }
   } 
}

//矩阵的乘法 
void multiplyMatrices(int A[3][3], int B[3][3], int C[3][3]) {
   int i,j,k;
    // 初始化矩阵 C
    for (i = 0; i < 3; i++) {
       for (j = 0; j < 3; j++) {
            C[i][j] = 0; // 确保矩阵 C 的初始值为 0
        }
    }
   for(i=0;i<3;i++){
   	for(j=0;j<3;j++){
   	  for(k=0;k<3;k++){
   	  	   C[i][j] += A[i][k]*B[k][j];
		 }
	   }
   } 
}

// 输出矩阵
void printMatrix(int matrix[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
	int A[3][3]={
	{1,2,3},
	{4,5,6},
	{7,8,9}};
	int B[3][3]={
	{9,8,7},
	{6,5,4},
	{3,2,1}};
	int C[3][3]={0};
	
	// 矩阵加法
    addMatrices(A, B, C);
    printf("Matrix A + Matrix B:\n");
    printMatrix(C);

    // 矩阵乘法
    multiplyMatrices(A, B, C);
    printf("\nMatrix A * Matrix B:\n");
    printMatrix(C);
	
	return 0;
} 
