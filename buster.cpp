


#include<string.h>
char *locatesubstr(char *str1,char *str2){
    int i=0;
    int length1 =strlen(str1);
//     int p=0;
    while(*str1 !='\0'){
        for (i = 0; *(str1 + i) == *(str2 + i); i++){
            if (*(str2 + i + 1) == '\0'){
                return str1;
            }
        }
        str1++;
    }
        return NULL;
}




#include<string.h>
char *locatesubstr(char *str1,char *str2){
    int i,cnt;
    i=0;
    cnt=0;
    while(*str1 != '\0'){
        while(*(str1+i)==*(str2+i)){
            cnt++;
            if(cnt== strlen(str2)){
                return str1;
            }
                i++;
        }
        cnt=0;
        i=0;
        str1++;
    }
        return NULL;
}



#include<string.h>
char *locatesubstr(char *str1,char *str2){
    int i,j;
    i=0;
    j=0;
    int length1,length2;
    length1=strlen(str1);
    length2 = strlen(str2);
    while(i<length1 && j< length2){
        if(str1[i]==str2[j]){
            i++;
            j++;
        }
        else{
            i=i-j+1;
            j=0;
        }
    }
    if(j==length2){
        return str1+i-j;
    }
        return NULL;
}
