#include<stdio.h>
#include<stdint.h>
int isprime( int a, int shuzu[],int zhishudegeshu);
int main (void) {
	int number =100;
	int cnt =1;
	int a =3;
	int primenum[number]={2};
	while( cnt < number ){
		if ( isprime ( a, primenum, cnt ) ){
			primenum[cnt++] = a;			
		} 
		a++;
	}
	int  i;
	for ( i=0; i<number; i++ ){
		printf("%d",primenum[i]);
		if( (i+1)%5 )
			printf("\t");		
		else 
			printf("\n");		
	}
return 0;
}
int isprime( int a, int shuzu[],int zhishudegeshu){
		int fanhui=1;
		int i; 
		for(i=0; i<zhishudegeshu; i++){
			if ( a % shuzu[i] == 0 ){
				fanhui = 0;
				break;
			}
		} 
		return fanhui;
	} 
