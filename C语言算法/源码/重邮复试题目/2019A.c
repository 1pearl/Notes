#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////2019_3_1：static的用法 
//int func(int a,int b){
//	static int m,i=2;
//	i+=m+1;
//	m=i+a+b;
//	return(m);
//}
//
//int main() {
//	int k=4,m=1,p;
//	p=func(k,m);
//	printf("%d\n",p);//输出结果为？ 
//	p=func(k,m);
//	printf("%d\n",p);//输出结果为？ 
//	return 0;
//}

////*a与**a的***&a的地址区别 
//int main(){
//	int a[][4] = {
//		{60,70,80,90},
//		{89,83,67,50},
//		{43,78,97,66},
//		{65,74,92,87}
//		};
//		
//		int *pt = *(a+1);
//		int i;
//		for(i=0;i<4;i++){
//			printf("%d\n",pt[i]);
//		}
		
//	printf("a = %d,a[0] = %d,&a = %d\n",*(*a),*(a[0]),*(*(*(&a))));//a = 60,a[0] = 60,&a = 60
//	int i;
//	for(i=0;i<4;i++){
//	    printf("a[0] + %d = %d\n",i,*(a[0]+i));	
//	} 
////	int i;
//	for(i=0;i<4;i++){
//		printf("a[1][%d] = %d\n",i,*(*(a+1)+i));//*(a+1)提取出a[1][0]的地址， 
//	} 
//	return 0;
//}

//int main(){
//			int a[][4] = {
//			{60,70,80,90},
//			{89,83,67,50},
//			{43,78,97,66},
//			{65,74,92,87}};
//	int i,j;
//	//数组指针表示二维数组，本质为一个指针，元素为int类型的一维数组 
//	//a为第一行的地址，a+1加了4*4=16字节，刚好与 p指向的数组int[4]一致，也为4*4=16B 
//	int (*p)[4] = a; 
//	//sizeof(a)：表示a这个二维数组的大小为4*4*4=64B
//	//sizeof(a[0])：表示二维数组第一行的地址为,4*4=16B 
//	for(i=0;i<sizeof(a)/sizeof(a[0]);i++){
//		for(j=0;j<sizeof(a[0])/sizeof(a[0][0]);j++){
//			printf("a[%d][%d] = %d ",i,j,*(*(p+i)+j));
//		  //printf("a[%d][%d] = %d\n",i,j,p[i][j]); 
//		}
//		printf("\n");
//	}
//	//指针数组表示二维数组，本质为一个数组，数组内元素为int*类型
//	int* b[4] = {a[0],a[1],a[2],a[3]}; 
//	printf("sizeof(b[0]) = %d\n",sizeof(b[0]));//b[0]表示b中第一个元素，为int*类型，在64位系统中占了8B 
//	printf("sizeof(b[0][0]) = %d\n",sizeof(b[0][0]));//b[0][0]表示a[0][0]，即占了4B	
//	for(i=0;i<sizeof(b)/sizeof(b[0]);i++){
//		for(j=0;j<4;j++){
//			printf("a[%d][%d] = %d ",i,j,p[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	//t指向a的第一行、
//	//因为二维数组是连续存储的所以可以根据这个特性按一维数组输出
//	int *t = a[0]; 
//	j=0;
//	int k=0;
//	for(i=0;i<16;i++){
//		printf("a[%d][%d] = %d ",k,j,t[i]);
//		j++;
//		if(j==4){
//			j=0;
//			printf("\n");
//			k++;
//		}
//	}
//	return 0;
//} 

////面试题目：二维数组，使用指针数组与数组指针的表示 
//int main(){
//	int a[3][4] = {
//		{1,2,3,4},
//		{3,4,5,6},
//		{5,6,7,8}
//		};
//	int i;
//	int (*p)[4] = a,*q = a[0];
//	for(i=0;i<3;i++){
//		if(i==0){
//			(*p)[i+i/2] = *q+1;
//		} else {
//			p++,++q;
//		}
//	}
//	for(i=0;i<3;i++){
//		printf("%d",a[i][i]);
//	}
//	printf("%d,%d\n",*((int*)p),*q); 	
//}

//void init(char* s){
//	s = (char *)malloc(sizeof(char)*128);
//}
//
//int main() {
//	char *str = NULL;
//	init(str);
//	strcpy(str,"hello");
//	free(str);
//	str = NULL;
//	return 0;
//}

//float *search(float (*p)[4],int n){
//  float* pt = *(p+1);
//  int i;
//  for(i=0;i<n;i++){
//  	if(*(*p+i)<60){
//  		pt = *p;
//	  }
//  }
//  return(pt);
//}
//
//int main(){
//	float s[][4]={
//		{60,70,80,90},
//		{89,83,67,50},
//        {43,78,97,66},
//		{65,74,92,87}};
//	float* p;
//	int i,j;
//	for(i=0;i<4;i++){
//		p=search(s+i,4);
//		if(p==*(s+i)){
//			printf("No.%d scores:\n",i);
//			for(j=0;j<4;j++){
//				printf("%5.2f",*(p+j));
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

void fun(char *w, int n) {
    char t, *s1, *s2;
    s1 = w;          // s1 指向字符串的开头
    s2 = w + n - 1;  // s2 指向字符串的末尾
    while (s1 < s2) {
        t = *s1++;   // 将 s1 指向的字符赋值给 t，然后 s1 向后移动
        *s1 = *s2--; // 将 s2 指向的字符赋值给 s1 指向的位置，然后 s2 向前移动
        *s2 = t;     // 将 t 赋值给 s2 指向的位置
    }
}

int main() {
    char *p = "1234567";  // 定义字符串 p，内容为 "1234567"
    fun(p, strlen(p));    // 调用 fun 函数，传入字符串 p 和其长度
    puts(p);              // 输出字符串 p
    return 0;
}





