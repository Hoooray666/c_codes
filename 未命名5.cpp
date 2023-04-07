#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
int main () {
	long pow;
	int x=1;
	pow=7;
	int shuzu[10]={1,0,1,0,0,0,0,1,0,0} ;
	for (int i=0;i<10;i++){
		if (shuzu[9-i]==1){
			x=(x*pow)%645;
		}
		pow=(pow*pow)%645;
		printf("µÚ%d´Î x=%d pow=%d  %d\n",i,x,pow,shuzu[9-i]);
	}



return 0;
}

