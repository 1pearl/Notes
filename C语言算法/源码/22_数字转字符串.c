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
		printf("�ޣ�\n");
    return 0;	
} 


//#include <stdio.h>
//#include <stdlib.h>
//
//unsigned int GetNotRepeatNum(unsigned int lValue) {
//    unsigned int i, num, temp1, temp2;
//    
//    // �� lValue + 1 ��ʼ������һ�����ظ���
//    for (i = lValue + 1; i < 100000; i++) {
//        int flag = 0;
//        num = i; // ���� i����ֱ���޸� i
//
//        while (num >= 10) {  
//            temp1 = num % 10;   // ȡ���һλ
//            num /= 10;          // ȥ�����һλ
//            temp2 = num % 10;   // ȡ�µ����һλ
//
//            if (temp1 == temp2) {  // ��������λ��ͬ
//                flag = 1;
//                break;
//            }
//        }
//
//        if (flag == 0) {  // �ҵ��˷�����������
//            return i;
//        }
//    }
//
//    return 0;  // δ�ҵ����ʵ���
//}
//
//int main() {
//    unsigned int n, result;
//    printf("������һ��������: ");
//    scanf("%u", &n);
//
//    result = GetNotRepeatNum(n);
//
//    if (result) {
//        printf("���� %u ����С���ظ���Ϊ: %u\n", n, result);
//    } else {
//        printf("�޺��ʵĲ��ظ�����\n");
//    }
//
//    return 0;
//}



