#include<stdio.h>
#include<math.h>
int main () {
    int cnt =0;
    int a;
    int shu;
    int m;
    scanf("%d",&shu);
    int i;
    for (i=100;i<=shu;i++){
    	int sum =0;
        int det ;
        int b;
        det = b= i;
        do{
            det /= 10;
            cnt ++;
        }while(det > 0);
        int weishu;
        weishu = pow(10,cnt-1);
//        printf ("%d ",weishu);
        do {    
            a = b / weishu;
            b %= weishu;
            sum += a*a;
            weishu /= 10;
        }while (weishu > 0 );
        printf("%d\n",sum);
//        if (i / m ==sum) 
//        printf("%d\n",i);
    }
    return 0;
}
