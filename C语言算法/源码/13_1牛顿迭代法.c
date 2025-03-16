//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#define ESP 1e-6
//#define Iter 1000
//
////求 2*x*x*x-4*x*x+3*x-6在1.5附近的根 
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
//			printf("导数为0\n");
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
//		printf("方程在1.5附近的根是%.3f\n",newton(x0));
//	}
//	return 0;
//} 


#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6 // 精度要求
#define MAX_ITER 1000 // 最大迭代次数

// 定义函数 f(x)
double f(double x) {
    return 2 * x * x * x - 4 * x * x + 3 * x - 6;
}

// 定义导数 f'(x)
double df(double x) {
    return 6 * x * x - 8 * x + 3;
}

// 牛顿迭代法
double newton(double x0) {
    double x = x0;
    int iter = 0;

    while (iter < MAX_ITER) {
        double fx = f(x);
        double dfx = df(x);

        if (fabs(dfx) < EPSILON) { // 导数为零，无法继续迭代
            printf("导数为零，无法继续迭代。\n");
            return NAN;
        }

        double x_next = x - fx / dfx; // 计算下一个近似值

        if (fabs(x_next - x) < EPSILON) { // 判断是否满足精度要求
            return x_next;
        }

        x = x_next; // 更新近似值
        iter++;
    }

    printf("达到最大迭代次数，未找到满足精度的解。\n");
    return NAN;
}

int main() {
    double x0 = 1.5; // 初始近似值
    double root = newton(x0);

    if (!isnan(root)) {
        printf("方程的根为：%.6f\n", root);
    }

    return 0;
}


 
