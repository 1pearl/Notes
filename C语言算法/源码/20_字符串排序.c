#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���ַ����Ӵ�С���� 
void sort(char* name[],int n){
	int i,j,k;
	char* temp;
	for(i=0;i<n-1;i++){//n���ַ���ֻ��Ҫn-1�αȽϼ��� 
		k=i;//�����һ���ַ�����С������k 
		for(j=i+1;j<n;j++){
			if(strcmp(name[i],name[j])<0){
				k = j;//˵��name[i]<name[j]�����ϴ�Ԫ�ص��±����k 
			} 
		}
		//����ҵ������Ԫ�أ��򽻻� name[i] �� name[k] 
		if(i == k){
			temp = name[i];
			name[i] = name[k];
			name[k] = temp;
		}
	}	
}

void print(char* name[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%s\n",name[i]);
	}
}

int main(){	
	// ��ʼ��һ��ָ�����飬�洢 6 ���ַ���
    char *name[6] = {"Sum", "Main", "Name", "Temp", "Char", "Void"};

    // �������������ַ��������������
    sort(name, 6);

    // ����������ַ���
    printf("Output String: \n");
    print(name, 6);

	return 0;
}


