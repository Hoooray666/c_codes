#include <stdio.h>
#include<stdlib.h>
int main(void) {
	int a=0;
	void* p;
	while (p = (malloc(100 * 1024*1024)))
		a++;
	printf("����%d00MB�Ŀռ�", a);
	return 0;
}
