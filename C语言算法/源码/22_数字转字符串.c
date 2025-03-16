#include <stdio.h>
#include <stdlib.h>

unsigned int GetNotRepeatNum(unsigned int lValue){
	int i,flag=0,num;
	int temp1,temp2;
	for(i=lValue+1;i<100000;i++){
		flag=0,num=i;
		while(num>=10){
		   temp1=num%10;
		   num/=10;
		   temp2=num%10;
		   if(temp1==temp2){
		   	  flag=1;
		   	  break;
		   }	
		}
		if(flag == 0){
			return i;
		}
	}
	return 0;
}

int main(){
	int n,re;
	scanf("%d",&n);
	re = GetNotRepeatNum(n);
	if(re) 
		printf("re = %d\n",re);
	else
		printf("无！\n");
    return 0;	
} 


//#include <stdio.h>
//#include <stdlib.h>
//
//unsigned int GetNotRepeatNum(unsigned int lValue) {
//    unsigned int i, num, temp1, temp2;
//    
//    // 从 lValue + 1 开始查找下一个不重复数
//    for (i = lValue + 1; i < 100000; i++) {
//        int flag = 0;
//        num = i; // 复制 i，不直接修改 i
//
//        while (num >= 10) {  
//            temp1 = num % 10;   // 取最后一位
//            num /= 10;          // 去掉最后一位
//            temp2 = num % 10;   // 取新的最后一位
//
//            if (temp1 == temp2) {  // 发现相邻位相同
//                flag = 1;
//                break;
//            }
//        }
//
//        if (flag == 0) {  // 找到了符合条件的数
//            return i;
//        }
//    }
//
//    return 0;  // 未找到合适的数
//}
//
//int main() {
//    unsigned int n, result;
//    printf("请输入一个正整数: ");
//    scanf("%u", &n);
//
//    result = GetNotRepeatNum(n);
//
//    if (result) {
//        printf("大于 %u 的最小不重复数为: %u\n", n, result);
//    } else {
//        printf("无合适的不重复数！\n");
//    }
//
//    return 0;
//}



