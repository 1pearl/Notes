#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////2019_3_1��static���÷� 
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
//	printf("%d\n",p);//������Ϊ�� 
//	p=func(k,m);
//	printf("%d\n",p);//������Ϊ�� 
//	return 0;
//}

////*a��**a��***&a�ĵ�ַ���� 
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
//		printf("a[1][%d] = %d\n",i,*(*(a+1)+i));//*(a+1)��ȡ��a[1][0]�ĵ�ַ�� 
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
//	//����ָ���ʾ��ά���飬����Ϊһ��ָ�룬Ԫ��Ϊint���͵�һά���� 
//	//aΪ��һ�еĵ�ַ��a+1����4*4=16�ֽڣ��պ��� pָ�������int[4]һ�£�ҲΪ4*4=16B 
//	int (*p)[4] = a; 
//	//sizeof(a)����ʾa�����ά����Ĵ�СΪ4*4*4=64B
//	//sizeof(a[0])����ʾ��ά�����һ�еĵ�ַΪ,4*4=16B 
//	for(i=0;i<sizeof(a)/sizeof(a[0]);i++){
//		for(j=0;j<sizeof(a[0])/sizeof(a[0][0]);j++){
//			printf("a[%d][%d] = %d ",i,j,*(*(p+i)+j));
//		  //printf("a[%d][%d] = %d\n",i,j,p[i][j]); 
//		}
//		printf("\n");
//	}
//	//ָ�������ʾ��ά���飬����Ϊһ�����飬������Ԫ��Ϊint*����
//	int* b[4] = {a[0],a[1],a[2],a[3]}; 
//	printf("sizeof(b[0]) = %d\n",sizeof(b[0]));//b[0]��ʾb�е�һ��Ԫ�أ�Ϊint*���ͣ���64λϵͳ��ռ��8B 
//	printf("sizeof(b[0][0]) = %d\n",sizeof(b[0][0]));//b[0][0]��ʾa[0][0]����ռ��4B	
//	for(i=0;i<sizeof(b)/sizeof(b[0]);i++){
//		for(j=0;j<4;j++){
//			printf("a[%d][%d] = %d ",i,j,p[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	//tָ��a�ĵ�һ�С�
//	//��Ϊ��ά�����������洢�����Կ��Ը���������԰�һά�������
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

////������Ŀ����ά���飬ʹ��ָ������������ָ��ı�ʾ 
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
    s1 = w;          // s1 ָ���ַ����Ŀ�ͷ
    s2 = w + n - 1;  // s2 ָ���ַ�����ĩβ
    while (s1 < s2) {
        t = *s1++;   // �� s1 ָ����ַ���ֵ�� t��Ȼ�� s1 ����ƶ�
        *s1 = *s2--; // �� s2 ָ����ַ���ֵ�� s1 ָ���λ�ã�Ȼ�� s2 ��ǰ�ƶ�
        *s2 = t;     // �� t ��ֵ�� s2 ָ���λ��
    }
}

int main() {
    char *p = "1234567";  // �����ַ��� p������Ϊ "1234567"
    fun(p, strlen(p));    // ���� fun �����������ַ��� p ���䳤��
    puts(p);              // ����ַ��� p
    return 0;
}





