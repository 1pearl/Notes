#include <stdio.h>
#include <stdlib.h>

//���� 
//int main(){
//	printf("������һ������!\n");
//	int n;
//	scanf("%d",&n);
//	int arr[n];
//	int i,a,b;
//	for(i=0;i<n;i++){
//		scanf("%d",&arr[i]);
//	}
//	while(scanf("%d%d",&a,&b) == 2){
//		if(a<0||b>=n||a>b){
//			printf("error!\n");
//			continue;
//		}
//		int sum=0;
//		for(i=a;i<=b;i++){
//			sum+=arr[i];
//		}
//		printf("sum = %d\n",sum);
//	}
//	free(arr);
//	return 0;
//}

//ǰ׺��
int main(){
	int n;
	printf("������һ������\n");
	scanf("%d",&n);
	int* arr = (int*)malloc((n+1)*sizeof(int));
	arr[0] = 0;
	int i;
	int num;
	for(i=1;i<=n;i++){
		scanf("%d",&num);
		arr[i] = arr[i-1]+num;
	}
	int a,b;
	while(scanf("%d%d",&a,&b)==2){
		printf("%d\n",arr[b+1]-arr[a]);
	}
	free(arr); 
	return 0;
} 
