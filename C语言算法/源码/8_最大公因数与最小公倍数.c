#include <stdio.h>
#include <stdlib.h>

//视频链接:https://www.bilibili.com/video/BV1Fw411X7fp/?spm_id_from=333.337.search-card.all.click&vd_source=4d8bdaa129d34a4905c8db625c08e44d 
// 49/35 = 1...14
// 35/14 = 2...7
// 14/7  = 2...0 
//最大公因数 * 最小公倍数 = 两数乘积 

int main(){
	int num1,num2,temp,cal,rem;
	printf("请输入两个数字\n");
	scanf("%d%d",&num1,&num2);
	if(num1 > num2){
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
	cal = num1*num2;
	while(num2 != 0) {
		rem = num1%num2;
		num1 = num2;
		num2 = rem;
	}
	printf("最大公因数是%d,最小公倍数是%d",num1,cal/num1); 
	return 0;
} 
