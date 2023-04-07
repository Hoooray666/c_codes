#include<stdio.h>
#include<stdint.h>
int main () {
	int a;
	int b;
	int i;
	scanf("%d%d",&a,&b);
	int cnt=0;
	for(i=1;i<=a;i++){
		int prime =1;
		int j;
		for(j=2;j<=i/2;j++){
			if (i%j ==0){
				prime =0;
				break;
			}
		}
		if (prime ==1){
			printf("%d\n",i);
			cnt ++;
		}
		if ( cnt == b)
			break;		
	}
return 0;
}

