#include<stdio.h>
int main(){
    int shuzua[1000];
    int shuzub[1000];
    int j=0;
    int i=0;
    int a,b;
    int m=1;
    int k;
    scanf("%d",&shuzua[0]);
    while(a!=-1){
        i++;
        scanf("%d",&a);
        shuzua[i]=a;
    }
    int prime =1;
    scanf("%d",&shuzub[0]);
    while(b!=-1){
        j++;
        scanf("%d",&b);
        shuzub[i]=b;
    }
    for(k=0;k<sizeof(shuzua)/sizeof(int)-1;k++){
        if(shuzub[0]==shuzua[k]){
            for(m=0;m<sizeof(shuzub)/sizeof(int);m++,k++){
                if(shuzua[k]!=shuzub[m]){
                    prime =0;
                    break;
                }
            }
            break;
        }
        
    }
    if (prime ==1){
        printf("ListB is not the sub sequence of ListA.");
    }
    else{
        printf("ListB is the sub sequence of ListA.");
    }
    return 0;
}
