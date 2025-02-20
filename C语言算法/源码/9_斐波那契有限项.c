#include <stdio.h>
#include <stdlib.h>

//  1    1    2    3    5    8    13
//num1 num2  res
//     num2  num1 res
int main(){
	int num1 = 1,num2 = 1;
	int i,n,temp,res;
	printf("你要求斐波那契数列前几项的和?\n");
	scanf("%d",&n);
	if(n <= 0){
		printf("error!");
		return;
	}
	if(n ==  1 || n ==2){
		printf("res = 1\n");
	} else {
	 for(i=2;i<n;i++){
		res = num1 + num2;
		num2 = num1;//顺序不能错！ 
		num1 = res;
	}
	printf("res = %d\n",res);		
	}

	return 0;
} 
