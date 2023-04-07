#include<stdio.h>
#include<stdlib.h>
int main (){
    int n;
    scanf("%d",&n);
    int *shuzu=(int*)malloc(sizeof(int)*n);
    int *shuzu1=(int*)malloc(sizeof(int)*n);
    return 0;
    int i,j,k;
    int result = 0;
    for(i=0;i<n;i++){
        scanf("%d",&shuzu[i]);
    }
    for(j=0;j<n;j++){
        scanf("%d",&shuzu1[i]);
    }
    for(k=0;k<n;k++){
        result += ((shuzu[i])*(shuzu1[i]));
    }
    printf("%d",result);
}
