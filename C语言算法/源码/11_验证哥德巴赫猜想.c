#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// 任何一个大于2的偶数总能表示为两个素数之和。比如24=5+19，其中5和19都是素数。
int isOOD(int n) {//判断是不是质数 
	int i;
	for(i=2;i<=sqrt(n);i++)
	if(n%i==0) break;//循环正常结束，没有比num1小的数整除num1,说明num1是素数 
	if(i > sqrt(n)) return 1;
	return 0;
}

int main(){
	int n,i,num1,num2;
	scanf("%d",&n);
    for(num1=2;num1<n;num1++){
    	for(i=2;i<=sqrt(num1);i++)
    	if(num1 % i == 0) break;	
		//循环正常结束，没有比num1小的数整除num1,说明num1是素数 
		if(i > sqrt(num1)){//说明num1是素数 
			//printf("num1 = %d是质数\n",num1);
			num2 = n - num1;
		    	for(i=2;i<=sqrt(num2);i++)
		    		if(num2 % i==0) break;
				if(i>sqrt(num2)){
				  printf("num2 = %d是质数\n",num2);
				  printf("%d + %d = %d\n",num1,num2,n);
				  break;	
		         }
		}
	}
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
