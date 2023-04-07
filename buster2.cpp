#include <stdio.h>

char *locatesubstr(char *str1,char *str2);
int main()
{
    char str1[505],str2[505];
    char *p;
    gets(str1);
    gets(str2);
    p=locatesubstr(str1,str2);

    if(p==NULL)    printf("NULL!\n");
    else    puts(p);

    return 0;
}

#include<string.h>
char *locatesubstr(char *str1,char *str2){
    int length1,length2;
    int cnt,i,j,k;
    i=0;
    length1 =strlen(str1);
    length2 =strlen(str2);
    while(*str1 != '\0'){
        if(*str1==*str2){
            do{
                if(*(str1+i)==*(str2+i)){
                    cnt++;
                    if(cnt == length2){
                        return str1;
                    }
                }
                i++;
            }while(*(str2+i) !='\0');
        }
        str1++;
    }
        return NULL
}
