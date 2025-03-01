#include <stdio.h>
#include <stdlib.h> 
 
int main(){
	char string[100];
	int i;
	char ch;
	fgets(string,sizeof(string),stdin);
    for(i = 0;(ch = string[i])!= '\0';i++){
    	if(ch >= 'a'&&ch <= 'z'){
    		string[i]-=32;
		} else if(ch >= 'A'&&ch <= 'Z'){
			string[i]+=32;
		}
	}	
	puts(string);

	return 0;
}
