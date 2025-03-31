#include <stdio.h>
#include <string.h>

int main(){
//	int a;
//	short b;
//	char c;
//    b = 0x100;
//    a = 0xff;
//	printf("%x & %x = %x, %x & 0xff = %x\n",b,a,b&a,b,b&0xff);
//    int a[3]={0,1,2};
//    printf("%d",a[3]);
    char dest[10];
    char* str = "Hello Ivan!";
//    strcpy(dest,str);
    strncpy(dest,str,4);
    memset(dest,'A',3);
	printf("strlen(%s) = %d\n",dest,strlen(dest));    
	return 0;
} 
