#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
//ǰ׺��
int main(){
    int m,n;//n��m�е�����
	printf("�����������������!\n");
	scanf("%d%d",&m,&n);
	int a[m];//��ÿ���ܺ� 
	int b[n];//��ÿ���ܺ�
	int i,j;
	
	//��ʼ�� 
	for(i=0;i<m;i++) a[i] = 0;
	for(i=0;i<n;i++) b[i] = 0; 
	
	//�ۼ�ÿ��֮����ÿ��֮�� 
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			int temp;
			scanf("%d",&temp);
			a[i] += temp;//���ܺ� 
			b[j] += temp;//���ܺ� 
			//printf("a[%d]=%d,b[%d]=%d\n",i,a[i],j,b[j]);
		}
	}
	
	//ǰ׺��
	for(i=1;i<m;i++) a[i] += a[i-1];
	for(i=1;i<n;i++) b[i] += b[i-1];
	
	//��ʼ��
	int row_sum = a[m-1]; 
	int column_sum = b[n-1];
	
	int diff;
	//�����������ֵ
	for(i=0;i<m-1;i++){
		diff = abs(a[i] - (a[m-1] - a[i]));
		if(diff<row_sum) row_sum = diff;
	}
	
	//�����������ֵ
	for(i=0;i<n-1;i++){
		diff = abs(b[i] - (b[n-1] - b[i]));
		if(diff<column_sum) column_sum = diff;		
	}
	
	int re = row_sum < column_sum ? row_sum : column_sum;
	
	printf("\n��С��ֵ = %d\n", re);
	return 0;
} 
