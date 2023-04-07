#include <stdio.h>

void swap(char* a, char* b) {
    char t = *a;
    *a = *b, *b = t;
}
int main() {
	char a ='a';
	char b ='b';
	swap(&a,&b);
	printf("%c,%c",a,b);
	return 0;
}

