#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

int main(){
	char str[1000];
	char ch;
	int word=0,count=0;
//输入字符串可以输入空格的方法1，2	
//	scanf("%[^\n]",&str);
	while((ch = getchar()) != '\n'&& ch != EOF){
		if(ch == ' '){
			word = 0;
		} else if(word == 0){
			word = 1;
			count++;
		}
	}
	printf("该段文本中单词的个数为:%d",count);
	
	return 0;
} 
