#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
int main () {
	char*s=(char*)malloc(sizeof(int)*10000000);
	gets(s);
	while(*s!='\0'){
		if(*s== '1'){
			printf("-");
		}
		if(*s=='0'){
			printf(".");
		}
		if(*s==' '){
			printf("/");
		}
		s++;
	} 
free(s);


return 0;
}

