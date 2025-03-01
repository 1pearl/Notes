#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//完数定义：
//一个数如果恰好等于它的因子之和，则这个数就是完数。例如6的因子为1，2，3，而
//6=1+2+3，因此6是“完数”。
int isPerfectNumber(int n){
    int i;
    int sum = 1;
    if(n == 1) return 0;
    for(i=2;i<=n/2;i++){
    	if(n%i==0){
    		sum+=i;
		}
	}
    return (sum == n);
}

int main(){	
	int i;
	for(i=1;i<=200;i++){
		if(isPerfectNumber(i)){
			printf("%d\n",i);
		}
	}
	return 0;
}

