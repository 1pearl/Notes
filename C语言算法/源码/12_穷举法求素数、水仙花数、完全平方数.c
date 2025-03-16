#include <stdio.h>
#include <math.h>

int isPrime(int n){//穷举法求素数 
	int i;
	if(n==0 || n==1) return 0;
	for(i=2; i*i <= n;i++)
	if(n%i==0) break;
	if(i > sqrt(n)) return 1;
	return 0; 
}

int isNarc_3(int num) {//假设都是3位数,求水仙花数 
    int a = num%10;
    int b = num/10%10;
    int c = num/100;
	if(a*a*a+b*b*b+c*c*c == num) return 1;
	return 0; 
}

int isNarc(int num) {
	int n,Origin,sum=0,R=0;
	Origin=num;
	while(num != 0){//判断num有几位 
	   num /= 10;
	   R++;//记录位数	
	}
    num = Origin;	
	while(num!=0){
		n=num%10;//获取最低位的值 
		sum+=pow(n,R);//累加数字的n次方 
		num/=10;//去掉最低位 
	}
	return sum == Origin;
} 

int isSquare(int num) {
	int i;
	for(i=1;i<=num;i++){
		if(i * i == num) return 1;
	}
	return 0;
}

void printPrime(int m,int n){
	int i;
    printf("%d~%d之间的素数为：",m,n);
	for(i=m;i<=n;i++){
		if(isPrime(i)){
			printf("%d ",i);
		}
	}
	printf("\n");	
}

void printNarc_3(int m,int n){
	int i;
    printf("%d~%d之间的水仙花数为：",m,n);
	for(i=m;i<=n;i++){
		if(isNarc_3(i)){
			printf("%d ",i);
		}
	}
	printf("\n");	
} 


void printNarc(int m,int n){
	int i;
    printf("%d~%d之间的水仙花数为：",m,n);
	for(i=m;i<=n;i++){
		if(isNarc(i)){
			printf("%d ",i);
		}
	}
	printf("\n");	
} 

void printSquare(int m,int n){
	int i;
    printf("%d~%d之间的完全平方数为：",m,n);
	for(i=m;i<=n;i++){
		if(isSquare(i)){
			printf("%d ",i);
		}
	}
	printf("\n");	
}

int main(){
	int m,n;
	scanf("%d%d",&m,&n);
//	printPrime(m,n);
//	printNarc_3(m,n);
//	printNarc(m,n);
	printSquare(m,n);
	return 0;
} 
