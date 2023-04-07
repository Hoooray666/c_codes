#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
int nPower(int x, int n);
int main () {
	int a ,b;
	scanf("%d%d",&a,&b);
	printf("%d",nPower(a,b));



return 0;
}



int nPower(int x, int n){
	if (n == 0){
		return 1 ;
	}
	else{
		return x*nPower(x, n-1);
	}
}
