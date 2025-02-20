#include <stdio.h> 
#include <stdlib.h>

int main(){
	printf("输入你要累加或累乘的数字个数\n");
	int i,j,res1=0,res2=1;
	int *p;
	scanf("%d",&j);
	p = (int*)malloc((sizeof(int)*j));
	printf("请输入你要累计计算的数字：\n");
	for(i=0;i<j;i++){
		scanf("%d",p+i);
	}
	for(i=0;i<j;i++) {
		res1 += *(p+i);
		res2 *= *(p+i);
	}
	printf("累加的结果为:%d\n",res1);
	printf("累乘的结果为:%d\n",res2); 
	
	free(p);
	p = NULL;
	return 0;
}


















