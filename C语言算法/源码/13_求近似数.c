#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//求多元函数的根 
double f(double x) {//定义一个积分函数x^2 
	return x*x - 2;
}

double d_f(double x) {
	return 2*x;
}
//定积分
/*
(*fun)(double):传入一个函数 
a:上限
b:下限
n:区间个数 
*/
double definite_integration(double (*f)(double),double a,double b,int n){
	double h = (b-a)/n;
	double sum = (f(a)+f(b))*0.5;
	int i;
	for(i=1;i<n;i++){
		sum+=f(a+h*i);
	}
	return sum * h;
	 
}
//牛顿迭代法
/*
f函数
df求导函数
x0猜的值
max_iter迭代次数
tol允许误差 
*/
double newtonMethod(double (*f)(double), double (*df)(double), double x0, int max_iter, double tol) {
    double x = x0;
    int i;
    for(i=0;i<max_iter;i++){
    	double fx = f(x);
    	double dfx = df(x);
    	double x_new = x - fx/dfx;
    	if(fabs(x_new-x)<tol && fabs(fx) < tol){ // 判断当前解是否足够精确
    		return x_new; // 如果误差足够小，返回当前解
		}
		x = x_new;  
	}
	printf("达到最大收敛次数，可能未收敛\n"); 
	return x;
}

double newtonMethod(double (*f)(double), double (*df)(double), double x0, int max_iter, double tol) {
    double x_new;
    for (int i = 0; i < max_iter; i++) {
        double fx = f(x0);
        double dfx = df(x0);

        if (fabs(fx) < tol) {  // 函数值足够小，认为收敛
            return x0;
        }

        x_new = x0 - fx / dfx;

        if (fabs(x_new - x0) < tol) {  // 变量变化量足够小，认为收敛
            return x_new;
        }

        x0 = x_new;
    }
    printf("达到最大收敛次数，可能未收敛\n");
    return x0;
}
//二分法
/*
f:函数 
a:猜测值1 
b:猜测值2 
tol:误差 
max_iter:迭代次数 
*/ 
double bisectionMethod(double (*f)(double), double a, double b, double tol, int max_iter) {
    double m;
    int i;
    for(i=0;i<max_iter;i++){
    	m = (a + b)/2;
    	if(fabs(f(m)) < tol){
    		return m;
		}
		if(f(a)*f(m)>0){// 判断中点函数值的符号，更新区间
			a = m; // 根在右半区间
		} else {
			b = m; // 根在左半区间
		}
	}
	return m;
}
//弦截法
/*
f:函数
x0:初始猜测值
x1:初始猜测值
tol:误差
max_iter:迭代次数 
*/
double secantMethod(double (*f)(double), double x0, double x1, double tol, int max_iter) {
    double x2;
    int i;
	for(i=0;i<max_iter;i++){
		x2 = x1 - (f(x1)*(x1-x0))/(f(x1)-f(x0));
		if(fabs(f(x2)) < tol) {
			return x2;
		}
		x0=x1;
		x1=x2;
	}
	return x2; 
}

int main(){
	
//	int a,b,n;
//	scanf("%d%d%d",&a,&b,&n);
//	printf("%.6f",definite_integration(f,a,b,n));
	
	double tol = 1e-6;
	int iter = 1000;
	double i,a,b;
//	scanf("%lf",&i);
//	printf("%.6f",newtonMethod(f,d_f,i,iter,tol));
	scanf("%lf%lf",&a,&b);
//	printf("%.6f",bisectionMethod(f,a,b,tol,iter));
	printf("%.6f",secantMethod(f,a,b,tol,iter));
	return 0;
} 

