#include <stdio.h>

//求斐波那契数列的第n项 

int fib(int n) {//递归 
	if(n<=0) return 0;
	else if(n==1) return 1;
	else return fib(n-1)+fib(n-2); 
}

int fib_(int n){//非递归 
	if(n==0) return 0;
	if(n==1) return 1;
	int a=0,b=1,c,i;
	for(i=2;i<=n;i++){
		c = a+b;
		a=b;
		b=c;
	}
	return b; 
} 

int main() {
    int i,n;
	printf("请输入要求前几项斐波那契数列\n");
	scanf("%d",&n);
	for(i=1;i<n;i++){
		printf("%d ",fib_(i));
	}
    return 0;
}


