#include<stdio.h>
#include<stdlib.h>
int main (){
    int n;
    scanf("%d",&n);
    int shuzu[200];
    int i;
    for(i=0;i<=n-1;i++){
        scanf("%d",&shuzu[i]);
    }
    int t=0;
    int p=0;
    int q=0;
    int prime =0;
    while(p<n){
        if((shuzu[p])%2!=0){
            for(q=p;q<n-1;q++){
                if((shuzu[q])%2==0 && shuzu[q]!=1){
                    prime = 1;
                    break;
                }
            }
            if(prime ==1){
                t = shuzu[p];
                shuzu[p]=shuzu[q];
                shuzu[q]=t;
            }
//             for(i=0;i<=n-1;i++){
//                 printf("%d ",shuzu[i]);
//             }
//             printf("\n");
        }
        p++;
        prime =0;
    }
    
        for(i=0;i<=n-1;i++){
            printf("%d ",shuzu[i]);
        }
    return 0;
}
