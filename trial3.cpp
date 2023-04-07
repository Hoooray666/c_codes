#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
void pai(int m[],int n);
int main () {
	int shuzu[6] = {1,2,5,4,9,8};
	pai(shuzu,6);
	for(int i = 0;i<sizeof(shuzu)/sizeof(shuzu[0]);i++){
		printf("%d \n",shuzu[i]);
	}



return 0;
}

void pai(int m[],int n){ //Ã°ÅÝÅÅÐò 
    int c;
    for (int i = 1; i <n ; i++) {
        for (int j = 0; j <n-i ; j++) {
            if (m[j]<m[j+1]){
                c=m[j];
                m[j]=m[j+1];
                m[j+1]=c;
            }
        }
    }
}
