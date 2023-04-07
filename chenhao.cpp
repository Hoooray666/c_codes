#include <stdio.h>
#include <string.h>
#include <math.h>
#define EPSILON  1e-5
long double f(long double x,long double b);
long double bisection(long double a,long double b,long double c);
int main(){
	long double  loss1 = 0.0;
	long double loss2 = 0.0;
	long double b = 100.0;
//	scanf("%.8.8.8.8.8.8.8.8.8.8.8.8.8.8.8.8lf",&b);
	long double r = sqrt(b*b-4);
	printf("%.16llf\n",r);
	long double x0 = (b-r)/2.0;
	printf("x0=%.16llf\n",x0);
	long double x1 = 2.0/(b+r);
	printf("x1=%.16llf\n",x1);
	long double x2 = bisection((x0-1),(x0+1),b);
	printf("x2=%.16llf,f = %.15llf\n",x2,f(x2,b));
	
	loss1 = fabs((x2-x0));
	loss2 = fabs((x2-x1));
	long double res1 = fabs((x2-x0)/x2);
	long double res2 = fabs((x2-x1)/x2);
	printf("loss1 = %.16llf,loss2 = %.16llf\n",loss1,loss2);
	printf("result1 is: %llf%%\n",res1*100);
	printf("result2 is: %llf%%",res2*100);
	
}
long double bisection(long double a,long double b,long double c){
	long double m = 0.0;
	if( f(a,c) * f(b,c) > 0){
		printf("error");
	}       
    while(fabs(b-a) > EPSILON){
    	m = (a+b)/2;
    	if( f(a,c) * f(m,c) < 0){
        	b = m;
        }
        else{
        	a = m;
		}
    }
    long double res =  (a + b) / 2     ;
    return res;
}

long double f(long double x,long double b){
	long double res = x*x-b*x+1;
	return res;
}

