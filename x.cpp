#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
int main () {
	int i ,j;
	for(i=0;i<=30;i++){
		for(j=0;j<=30-i;j++){
			if(2*i+4*j == 90 && i+j==30){
				printf("���� %dֻ ������%d ֻ",i,j);
				break;
			}
		}
//		break;
	} 



return 0;
}

