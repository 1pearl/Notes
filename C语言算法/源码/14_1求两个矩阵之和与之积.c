#include <stdio.h>
#include <stdlib.h>

int main(){
	int a[3][3];
	int b[3][3];
	int c[3][3]={0};//存矩阵相加结果 
	int d[3][3]={0};//存矩阵相乘结果 
	int i,j,k,m,n,p,q;
    scanf("%d%d",&m,&n);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
    scanf("%d%d",&p,&q);
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<m;i++){//矩阵相加 
		for(j=0;j<n;j++){
			c[i][j] = a[i][j]+b[i][j];
		}
	}
	//输出相加结果
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}	    
	for(i=0;i<m;i++){//a_mn b_pq = cmq两矩阵相乘 
		for(j=0;j<q;j++){
			d[i][j]=0;
			for(k=0;k<n;k++){
				d[i][j] += a[i][k]*b[k][j];
			}
		}
	}
	for(i=0;i<m;i++){//输出相乘的结果 
	 for(j=0;j<q;j++){
			printf("%d ",d[i][j]);
		}
		printf("\n");
	}
	return 0;	 
}
