#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("ÇëÊäÈëÒªÅÐ¶ÏµÄ×Ö·û£º\n");
	char c;
	scanf("%c",&c);
	if(c>='0'&&c<='9'){
		printf("Êý×Ö\n"); 
	} else if(c>='a'&&c<='z') {
		printf("Ð¡Ð´×ÖÄ¸\n");
 		printf("´óÐ´×ÖÄ¸\n");
	} else {
		printf("ÆäËû\n");
	}
	return 0;
} 
