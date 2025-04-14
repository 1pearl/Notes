#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
//前缀和
int main(){
    int m,n;//n行m列的数组
	printf("请输入数组的行与列!\n");
	scanf("%d%d",&m,&n);
	int a[m];//存每行总和 
	int b[n];//存每列总和
	int i,j;
	
	//初始化 
	for(i=0;i<m;i++) a[i] = 0;
	for(i=0;i<n;i++) b[i] = 0; 
	
	//累加每行之和与每列之和 
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			int temp;
			scanf("%d",&temp);
			a[i] += temp;//行总和 
			b[j] += temp;//列总和 
			//printf("a[%d]=%d,b[%d]=%d\n",i,a[i],j,b[j]);
		}
	}
	
	//前缀和
	for(i=1;i<m;i++) a[i] += a[i-1];
	for(i=1;i<n;i++) b[i] += b[i-1];
	
	//初始化
	int row_sum = a[m-1]; 
	int column_sum = b[n-1];
	
	int diff;
	//计算行区域差值
	for(i=0;i<m-1;i++){
		diff = abs(a[i] - (a[m-1] - a[i]));
		if(diff<row_sum) row_sum = diff;
	}
	
	//计算列区域差值
	for(i=0;i<n-1;i++){
		diff = abs(b[i] - (b[n-1] - b[i]));
		if(diff<column_sum) column_sum = diff;		
	}
	
	int re = row_sum < column_sum ? row_sum : column_sum;
	
	printf("\n最小差值 = %d\n", re);
	return 0;
} 
