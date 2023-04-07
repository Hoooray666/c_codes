#include<stdio.h>
void f(int *p);
int main() {
	
	int a;
	a = 4 ;
	f(&a);
	printf("%p \n",&a);
	
	
	 
	return 0;
}
void f(int *p){
	printf ("%p",p);
	*p=8;
}
