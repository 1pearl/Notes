#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

int main(){
//	char str[1000];
	char ch;
	int flag=0,count=0;
//�����ַ�����������ո�ķ���1��2	
//	scanf("%[^\n]",&str);
	while((ch = getchar()) != '\n'&& ch != EOF){
		if(ch == ' '){
			flag = 0;
		} else if(flag == 0){
			flag = 1;
			count++;
		}
	}
	printf("�ö��ı��е��ʵĸ���Ϊ:%d",count);
	
	return 0;
} 

//int main(){
//	char str[100]={0};
//	fgets(str,sizeof(str),stdin);
//	int i,count=0;
//	for(i=0;str[i]!='\0';i++){
//		if(isalpha(str[i])&&!isalpha(str[i+1])){
//			count++;
//		}
//	}
//	printf("%s����%d������\n",str,count);
//	return 0;
//}

