#include<stdio.h>
int main(){
    int n;
//     int m;
    int a,b;
    scanf("%d",&n);
//     int ave[n];
    int shuzu[n+1][n+1];
    int i;
    int j;
//    int p;
    int k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&shuzu[i][j]);
//            shuzu[i][j]=p;
            shuzu[i][n] += shuzu[i][j];
        }
    }
int c,shuzu1[110],q;
	for(c=0;c<n-1;c++)        
	{
	    for(j=n-1;j>=c+1;j--)
	    {
		    if(shuzu[j][n]<shuzu[j-1][n])
		    {
			    for(k=0;k<=n;k++)
			    {
				    shuzu1[k]=shuzu[j][k];      
				    shuzu[j][k]=shuzu[j-1][k];
				    shuzu[j-1][k]=shuzu1[k];
			    }
		    }
	    }
    }
    for(a=0;a<n;a++){
        for(b=0;b<n-1;b++){
            printf("%d ",shuzu[a][b]);
        }
        printf("%d",shuzu[a][b]);
        printf("\n");
    }
    return 0;
}
