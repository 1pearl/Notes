//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#define ESP 1e-6
//#define Iter 1000
//
////�� 2*x*x*x-4*x*x+3*x-6��1.5�����ĸ� 
//double f(double x){
//	return 2*x*x*x-4*x*x+3*x-6; 
//}
//
//double df(double x){
//	return 6*x*x - 8*x + 3;
//}
//
//double newton(double x0){
//	double x = x0;
//	int iter = 0;
//	while(iter < Iter){
//		double f_ = f(x);
//		double df_ = df(x);
//		
//		if(fabs(df_) < ESP){
//			printf("����Ϊ0\n");
//			return 0;
//		}
//		double x_next = x - f_/df_;
//		
//		if(fabs(x_next - x) < ESP) {
//			return x_next;
//		}
//		x=x_next;
//		iter++;
//	}
//	return 0;
//}
//
//int main(){
//	double x0 = 1.5;
//	if(newton(x0)){
//		printf("������1.5�����ĸ���%.3f\n",newton(x0));
//	}
//	return 0;
//} 


#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6 // ����Ҫ��
#define MAX_ITER 1000 // ����������

// ���庯�� f(x)
double f(double x) {
    return 2 * x * x * x - 4 * x * x + 3 * x - 6;
}

// ���嵼�� f'(x)
double df(double x) {
    return 6 * x * x - 8 * x + 3;
}

// ţ�ٵ�����
double newton(double x0) {
    double x = x0;
    int iter = 0;

    while (iter < MAX_ITER) {
        double fx = f(x);
        double dfx = df(x);

        if (fabs(dfx) < EPSILON) { // ����Ϊ�㣬�޷���������
            printf("����Ϊ�㣬�޷�����������\n");
            return NAN;
        }

        double x_next = x - fx / dfx; // ������һ������ֵ

        if (fabs(x_next - x) < EPSILON) { // �ж��Ƿ����㾫��Ҫ��
            return x_next;
        }

        x = x_next; // ���½���ֵ
        iter++;
    }

    printf("�ﵽ������������δ�ҵ����㾫�ȵĽ⡣\n");
    return NAN;
}

int main() {
    double x0 = 1.5; // ��ʼ����ֵ
    double root = newton(x0);

    if (!isnan(root)) {
        printf("���̵ĸ�Ϊ��%.6f\n", root);
    }

    return 0;
}


 
