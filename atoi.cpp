#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int myAtoi(char * s){
    int length = strlen(s);
    int i;
	int det =1;
    while(*s!='\0'&&*s==' '){
    	s++;
	}
	if(*s=='-' || *s == '+'){
		if(*s=='-'){
			det =-1;
		}
		s++;
	}
    int shu=0;
    if(*s < 48 || *s > 57){     
        return 0;
    }
    if(*s>=48 &&*s<=57){
        for(;(*s>=48 && *s<=57)&&(*s!='\0');s++){
            if(det ==0){
                if(shu*-1<INT_MIN/10||(shu*-1==INT_MIN/10 &&*s<INT_MIN%10)){
                    return INT_MIN;
                }
            }
            if(shu >INT_MAX/10 ||(shu==INT_MAX/10 && *s> INT_MAX%10)){
                return INT_MAX;
            }
            shu =*s-48+shu*10;
        }
    }
    if(det ==0){
        return shu*-1;
    }
    else 
        return shu;
}

int main(){
	char*s;
	gets(s);
	int a = myAtoi(s);
	printf("%d",a);
} 
