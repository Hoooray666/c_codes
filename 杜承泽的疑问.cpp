#include<stdio.h>
#include<math.h>
int main(){
    int n,t,num,r;
    int single=0;
    int amount=0;
    int i=0; 
    scanf("%d",&t);
    for(i=0;i<t;i++){
    
        scanf("%d",&num);
        do{
            scanf("%d",&single);
            amount=amount+single;
            num--;
        }while(num!=0);
        if(amount<100){
            printf("%d\n",amount);
        }
        else if(amount>=100&&amount<200){
            r=amount-30;
   printf("%d\n",r);
        }
        else if(amount>=200&&amount<300){
            r=amount-70;
   printf("%d\n",r);
        }
        else  if(amount>=300&&amount<400){
            r=amount-110;
   printf("%d\n",r);
        }
         else if(amount>=400){
            r=amount-160;
   printf("%d\n",r);
        }
        r=0;
  amount=0; 
    }
    
    return 0;
}
