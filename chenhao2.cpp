#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>
int main(){
	long double lb=0.0;
	double d =0.0;
	float f =0.0;
	while(1+lb > 1){
		lb/=2;
	}
	while(1+d > 1){
		d/=2;
	}
	while(1+f > 1){
		f/=2;
	}
	printf( "longdouble = %.2e\n",lb);
	printf( "double = %.2e\n",d);
	printf( "float = %.2e\n",f);
	
	 
	
}
