#include <stdio.h>
#include <stdlib.h>
/*
猴子第一天摘了若干个桃子，当即吃了一半，还不解馋，又多吃了一个；
第二天，吃剩下的桃子的一半，还不过瘾，又多吃了一个；
以后每天都吃前一天剩下的一半多一个，到第n天想再吃时，只剩下一个桃子了。
问第一天共摘了多少个桃子？
Sn = 1;
Sn = 1/2 x Sn-1 - 1;
Sn-1 = 2(Sn-1 + 1); 
*/ 
/*
n,m：第n天剩余m个桃子 
*/
int sum_1(int n,int m){
	int sum=m;
	while(n-1){//减1是从第9天开始向后推，第10天只是提供了一个初值，不能迭代 
		sum = 2*(sum+1);
		n--;
	}
//	int i;
//	for(i=9;i--;i>0){
//		sum = 2*(sum+1); 
//	} 

	return sum;
}

int sum_2(int n){
	if(n == 10){
		return 1;
	}
	return 2*(sum_2(n+1)+1);
}

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    printf("第1天摘了%d个桃子\n",sum_2(n));
	return 0;
} 
