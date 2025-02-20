#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("请输入要判断的年份：\n");
	int year;
	scanf("%d",&year);
	if((year%4==0&&year%100!=0)||year%400==0){//如果年份能被4整除但不能被100整除，则为闰年。如果年份能被400整除，也是闰年。
		printf("为闰年！\n");
	}else {
		printf("不为闰年！\n");
	} 
	return 0;
}
