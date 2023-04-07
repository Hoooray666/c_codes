#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
int main () {
	char*s=(char*)malloc(sizeof(char)*100000);
	gets(s);
	int n=0;
	while(*s!='\0'){
		for(;*s!='0';s++){
			n+=*s-'0';
		}
		
		printf("%c ",n%26+96);
		s++;
		n=0;
	}




return 0;
}

