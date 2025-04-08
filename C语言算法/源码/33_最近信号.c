/*
在一个数轴上有若干个信号点，在数轴上任意一点到信号点的距离的平方为距离量，
该点的所有距离量的总和为总距离量，总距离量最短的称为热点。
先需要写一个程序，输入一组信号点，输出热点。
输入：一个以上的数
输出：热点值
例：输入：1，3，7，42.2
输出：13.3
*/
//思路：即是找平均值 
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
	printf("请输入这%d个信息点\n",n);
	for(i=0;i<n;i++){
		scanf("%lf",&a[i]);
	}
	double target = find_target(a,n);
	printf("热点是%.2lf\n",target); 
	return 0;
}
