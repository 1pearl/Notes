/*
��һ�������������ɸ��źŵ㣬������������һ�㵽�źŵ�ľ����ƽ��Ϊ��������
�õ�����о��������ܺ�Ϊ�ܾ��������ܾ�������̵ĳ�Ϊ�ȵ㡣
����Ҫдһ����������һ���źŵ㣬����ȵ㡣
���룺һ�����ϵ���
������ȵ�ֵ
�������룺1��3��7��42.2
�����13.3
*/
//˼·��������ƽ��ֵ 
#include <stdio.h>
double find_target(double a[],int n){
	double sum=0;
	int i;
	for(i=0;i<n;i++){
		sum+=a[i];
	}
	return sum/(double)n;
}
int main(){
	int i,n;
	scanf("%d",&n); 
	double a[n];
	printf("��������%d����Ϣ��\n",n);
	for(i=0;i<n;i++){
		scanf("%lf",&a[i]);
	}
	double target = find_target(a,n);
	printf("�ȵ���%.2lf\n",target); 
	return 0;
}
