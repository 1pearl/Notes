#include <stdio.h>

//���� 
int removeElement_1(int a[],int len,int target){
	int i,j;
	for(i=0;i<len;i++){
		if(a[i] == target){
			for(j=i+1;j<len;j++){
			    a[j-1] = a[j];
			}
			i--;
			len--;						
		}
	}
	return len;
}

//����ָ��
int  removeElement_2(int a[],int len,int target){
    int slowPoint=0,fastPoint=0;
    for(fastPoint = 0;fastPoint<len;fastPoint++){
    	if(a[fastPoint] != target){
    		a[slowPoint++] = a[fastPoint];
		}
	}
	return slowPoint;
}

int main(){
	int arr[] = {2,2,3,3,1,2,3,5,10};
	int n;
	printf("��������Ҫɾ����Ԫ��:\n");
	scanf("%d",&n);
	int re =  removeElement_1(arr,sizeof(arr)/sizeof(arr[0]),n);
	printf("ɾ����%d������鳤��Ϊ%d\n",n,re);
	return 0;
} 
