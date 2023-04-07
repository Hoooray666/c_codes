#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(char *a[],int size);
int main(){
    int n;
    int i;
    scanf("%d",&n);
    char str[1000000];
    char*shuzu[100];
    shuzu[0]=str;
    getchar();
    for(i=0;i<n;i++){
        gets(shuzu[i]);
        if(i!=n-1){
            shuzu[i +1]=shuzu[i]+strlen(shuzu[i])+1;
        }
//         int length = strlen(str);
//         shuzu[i]=(char*)malloc(sizeof(char)*length+1);
//         strcpy(shuzu[i],str);
    }
    
    sort(shuzu,n);
    for(i=0;i<n;i++){
        puts(shuzu[i]);
    }
    
    return 0;
}
void sort(char *a[],int size)
{
    char *temp;
    int i,j,min;
    for(i=0;i<=size-2;i++)
    {
        min=i;
        for(j=i+1;j<=size-1;j++)
        {
            if(strcmp(a[min],a[j])>0)
                min=j;
        }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    } 
}
