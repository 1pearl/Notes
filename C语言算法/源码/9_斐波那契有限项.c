//#include <stdio.h>
//#include <stdlib.h>
//
////0   1    1    2    3    5    8    13
////num1 num2  res
////     num2  num1 res
//int main(){
//	int num1 = 0,num2 = 1;
//	int i,n,temp,res;
//	printf("��Ҫ��쳲���������ǰ����ĺ�?\n");
//	scanf("%d",&n);
//	if(n <= 0){
//		printf("error!");
//		return;
//	}
//	if(n ==  1 || n ==2){
//		printf("res = 1\n");
//	} else {
//	 for(i=2;i<n;i++){
//		res = num1 + num2;
//		num2 = num1;//˳���ܴ� 
//		num1 = res;
//	}
//	printf("res = %d\n",res);		
//	}
//
//	return 0;
//} 


#include <stdio.h>

int main() {
    int n;
    printf("Enter a number n: ");
    scanf("%d", &n);  // ����Ҫ������쳲��������е�����

    // �������
    if (n < 0) {
        printf("Invalid input! Please enter a non-negative integer.\n");
        return 0;
    }

    int a = 0, b = 1, sum = 0, fib;
    
    // ����ǰn��ͣ���쳲��������еĵ�n��
    if (n == 0) {
        fib = 0;
        sum = 0;
    } else if (n == 1) {
        fib = 1;
        sum = 1;
    } else {
        sum = a + b;  // ��ʼ��sumΪF(0)+F(1)
        for (int i = 2; i <= n; i++) {
            fib = a + b;  // ����쳲��������еĵ�ǰ��
            sum += fib;   // �ۼӵ��ܺ���
            a = b;        // ����a
            b = fib;      // ����b
        }
    }

    // ������
    printf("The %dth Fibonacci number is: %d\n", n, fib);
    printf("The sum of the first %d Fibonacci numbers is: %d\n", n, sum);

    return 0;
}


