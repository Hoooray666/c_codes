#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* fizzbuzz(int shu);
char* trans(int shu);
    char shuzu[6]={0};
int main () {
	char *q=trans(28);
		puts(trans(28));
		puts(q);
return 0;
}
char* trans(int shu){
    int cnt=0;
    int p=shu;
    while(p>0){
        p/=10;
        cnt++;
    }
    int i=0;
    while(shu>0){
        shuzu[cnt-i-1]=shu%10+'0';
        shu/=10;
        i++;
    }
//    puts(shuzu);
    return shuzu;
}
char* fizzbuzz(int shu){
    char*shuzu4=(char*)malloc(sizeof(char)*100);
    char shuzu1[4]={'F','i','z','z'};
    char shuzu2[4]={'B','u','z','z'};
    char shuzu3[8]={'F','i','z','z','B','u','z','z'};
    if((shu)%3==0 && (shu)%5!=0){
        return shuzu1;
    }
    if((shu)%5==0 && (shu)%3!=0){
        return shuzu2;
    }
    if((shu)%5==0 && (shu)%3==0){
        return shuzu3;
    }
    else{
        return trans(shu);
    }
}


