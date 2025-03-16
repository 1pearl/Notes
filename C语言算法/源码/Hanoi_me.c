#include <stdio.h>

void print(char x,char y){
	printf("%c->%c\n",x,y);
}

void hanoi_move(int n,char start,char temp,char end){
	if(n == 1){
		print(start,end);
	} else {
		hanoi_move(n-1,start,end,temp);
		print(start,end);
		hanoi_move(n-1,temp,start,end);
	}
}

int main(){
	char A = 'A',B = 'B',C = 'C';
	int n;
	printf("输入的圆盘个数为\n");
	scanf("%d",&n);
	hanoi_move(n,A,B,C); 

	return 0;
}
