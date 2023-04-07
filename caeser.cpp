#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
int main () {
	char*s=(char*)malloc(sizeof(char)*100);
	scanf("%s",s);
	puts(s);
	for(int n =0;n<26;n++){
			while(*s!='\0'){
				if(97<=*s && *s<=122){
					printf("%c",(*s+n-57)%26+97);
				}
				else{
					printf("%c",*s);
				}
				s++;
			}
			printf("\n");
	}

free(s);


return 0;
}

