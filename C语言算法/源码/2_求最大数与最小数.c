#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,j,max,min;
	int *p;
	printf("请输入你要输入数字的个数\n");
	scanf("%d",&j);
	p = (int*)malloc(sizeof(int)*j);
	printf("请输入%d个数\n",j);
	for(i=0;i<j;i++) {
		scanf("%d",p+i);
	}
	max = min = *p; 
	for(i=1;i<j;i++){
		if(max < *(p+i)) {
		   max = *(p+i);	
		}
		if(min > *(p+i)) {
		   min = *(p+i);	
		}
	} 
	printf("最大值是%d,最小值是%d",max,min);
	free(p);
	p = NULL;
	return 0;
} 


