#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//�������壺
//һ�������ǡ�õ�����������֮�ͣ����������������������6������Ϊ1��2��3����
//6=1+2+3�����6�ǡ���������
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

