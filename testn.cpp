#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
int main () {
//	int i;
//	int a[10]  ={1,20,3};
//	int *p = &a[3];
//	int*q = p+2;
//	for(int i = 3;i<10;i++){
//		a[i]= a[i-2]+2;
//	}
//	*p = *q;
//	q++;
//	*(q+1) = *(p+1);
//	printf("%d\n",*a+*q-*p);
//	for(int i =4;i<7;i++){
//		printf("%d ",a[i]);
//	}
	int i, k=0;  //i用于遍历 ,k用来计数 
	int a, aa[40];
	int*p =aa;  //a是字符，aa是字符数组 
	scanf("%d",p);
	printf("%c",*p+'a');
	while(p != NULL){
		p++;
		scanf("%d",p);
//		printf("%d",*p);
		printf("%c",*p+'a');
	}
	
	
return 0;
}

