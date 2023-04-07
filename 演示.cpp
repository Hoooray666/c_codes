#include<stdio.h>
void swap(int *pa,int *pb);
int main (void){
	int a=3;
	int  b= 4;
	 swap(&a,&b);
	 printf("a=%d b=%d",a,b);
	 
	return 0;
	
}
void swap (int *pa ,int *pb){
	int t;
	t = *pa;
	*pa=*pb;
	*pb =t;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
	
	
	
}
