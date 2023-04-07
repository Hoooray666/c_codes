#include<stdio.h>
#include<math.h>
#define EPSILON 1e-8
int jiecheng(int a);
int main () {
    double ex;
    double x;
    int i ;
    scanf ("%lf",&x);
    i = 1 ;
    ex = 1 ;
    if (x==0.0) {
        ex= 1;
    }
    else {
            while(1) {
            ex += ((pow(x,i)) / jiecheng(i));
            printf("%.4lf\n",((pow(x,i)) / jiecheng(i)));
            printf("%.4lf\n",ex);
            i++;
            if(fabs((pow(x,i)) / jiecheng(i)) < EPSILON)
                break;
            }
    printf("%.4lf",ex);
    }
    return 0;
}
int jiecheng(int a) {
    int i;
    int sum =1;
    for(i=1; i <= a ;i++){
        sum *= i;
    }
    return sum;
}
