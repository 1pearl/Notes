#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//将字符串从大到小排序 
void sort(char* name[],int n){
	int i,j,k;
	char* temp;
	for(i=0;i<n-1;i++){//n个字符串只需要n-1次比较即可 
		k=i;//假设第一个字符串最小，存入k 
		for(j=i+1;j<n;j++){
			if(strcmp(name[i],name[j])<0){
				k = j;//说明name[i]<name[j]，将较大元素的下标存入k 
			} 
		}
		//如果找到更大的元素，则交换 name[i] 和 name[k] 
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
	// 初始化一个指针数组，存储 6 个字符串
    char *name[6] = {"Sum", "Main", "Name", "Temp", "Char", "Void"};

    // 调用排序函数对字符串数组进行排序
    sort(name, 6);

    // 输出排序后的字符串
    printf("Output String: \n");
    print(name, 6);

	return 0;
}


