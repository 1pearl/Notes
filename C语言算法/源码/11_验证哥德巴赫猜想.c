#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//// 任何一个大于2的偶数总能表示为两个素数之和。比如24=5+19，其中5和19都是素数。
//int isOOD(int n) {//判断是不是质数 
//	int i;
//	for(i=2;i<=sqrt(n);i++)
//	if(n%i==0) break;//循环正常结束，没有比num1小的数整除num1,说明num1是素数 
//	if(i > sqrt(n)) return 1;// 如果循环正常结束，说明 n 是素数
//	return 0;
//}

int isOdd(int n){
	int i;
	if(n<2) return 0;//负数、0、1不是素数 
	if(n==2) return 1;//2是素数 
	if(n%2==0) return 0;//偶数不是素数 
	for(i=3;i<=sqrt(n);i++){//在0~sqrt(n)之间可以被整除的不是素数 
		if(n%i==0) return 0;
	}
	return 1;
} 

int main(){
	int n,i,num1,num2;
	scanf("%d",&n);
	if(n<=2 || n%2 != 0 ){
		printf("请输入大于2的偶数\n");
		return; 
	 } 
	 for(i=2;i<=n/2;i++){
	 	if(isOdd(i)&&isOdd(n-i)){
	 		printf("%d=%d+%d\n",n,i,n-i);
	 		return;
		 }
	 }
	printf("未找到满足条件的素数对\n");
	
//    for(num1=2;num1<n;num1++){
//    	for(i=2;i<=sqrt(num1);i++)
//    	if(num1 % i == 0) break;	
//		//循环正常结束，没有比num1小的数整除num1,说明num1是素数 
//		if(i > sqrt(num1)){//说明num1是素数 
//			//printf("num1 = %d是质数\n",num1);
//			num2 = n - num1;
//		    	for(i=2;i<=sqrt(num2);i++)
//		    		if(num2 % i==0) break;
//				if(i>sqrt(num2)){
//				  printf("num2 = %d是质数\n",num2);
//				  printf("%d + %d = %d\n",num1,num2,n);
//				  break;	
//		         }
//		}
//	}
//    for(i=2;i<n;i++){
//    	if(isOOD(i)){
//    		num1=i;
//    		num2=n-num1;
//    		if(isOOD(num2)){
//    			printf("%d + %d = %d\n",num1,num2,n); break;
//			}
//		}
//	}
    
	return 0;
} 
