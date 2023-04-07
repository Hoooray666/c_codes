#include<stdio.h>
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int shuzu[m][n];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&shuzu[i][j]);
        }
    }
    int a,b;
    scanf("%d%d",&a,&b);
    int c,d;
    c=a-1;
    d=b-1;
    int sum=0;
    if (m<3&&n>=3){
        if(c==0&&d==0){
            sum+=shuzu[0][1];
            sum+=shuzu[1][0];
        }
        else if (c==1&&d==0){
            sum+=shuzu[0][0];
            sum+=shuzu[1][1];
        }
        else if(c==1&&d==n){
            sum+=shuzu[0][m];
            sum+=shuzu[1][m-1];
        }
        else if(c==0&&d==n){
            sum+=shuzu[1][m];
            sum+=shuzu[0][m-1];
        }
        
    }
    else if (m>=3&&n<3){
        if(d==0&&c==0){
            sum+=shuzu[0][1];
            sum+=shuzu[1][0];
        }
        else if (d==1&&c==0){
            sum+=shuzu[0][0];
            sum+=shuzu[1][1];
        }
        else if(d==1&&c==m){
            sum+=shuzu[n][0];
            sum+=shuzu[n-1][1];
        }
        else if(d==0&&c==m){
            sum+=shuzu[n][1];
            sum+=shuzu[n-1][0];
        }
        
    else{
        if(c!=0&&c!=m&&d!=0&&d!=n){
            sum+=shuzu[c][d+1]+shuzu[c][d-1]+shuzu[c+1][d]+shuzu[c-1][d]+shuzu[c-1][d+1]+shuzu[c+1][d+1]+shuzu[c-1][d-1]+shuzu[c+1][d-1];
        }
        else if((c==0&&d==0)||(c==0&&d==n)||(c==m&&d==n)||(c==m&&d==n)
    }
        
    }
    return 0;
}
