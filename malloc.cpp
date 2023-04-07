#include<stdio.h>
#include<stdint.h>
#include<stdlib.h> 
int main () {

int a=0;
	void* p;
	while (p = (malloc(100 * 1024*1024)))
		a++;
	printf("给了%d00MB的空间", a);
	return 0;



}

