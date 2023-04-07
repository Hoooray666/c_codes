#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
int main () {
	int cnt=4;
	int i=11;
	while(i<=10000){
		if(i%3!=0 && i%4!=0 && i%7!=0 && i%11!=0 ){
			cnt++;
		}
		
		printf("i=%d cnt=%d\n",i,cnt);
		i++;
	}
	printf("%d",cnt);


return 0;
}

