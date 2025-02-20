#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>  

char mytoupper(char c){
	if(c >= 'a'&& c <= 'z'){//小写转大写 -32 
		return c - 32;
	}
	return c;
}

char mytolower(char c){//大写转小写 +32 
	if(c >= 'A'&&c <= 'Z'){
		return c + 32;
	}
	return c;
}
 
int main(){
	char c;
	printf("请入要要转换的字母："); 
	scanf("%c",&c);//取地址！！！ 
	printf("c = %c\n",c);
	printf("upper = %c\n",toupper(c)); //ctype.h toupper();
	printf("lower = %c\n",tolower(c)); //ctype.h tolower();
	printf("upper = %c\n",mytoupper(c));
	printf("lower = %c\n",mytolower(c));

	return 0;
}
