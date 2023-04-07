#include<stdio.h>
#include<stdint.h>
int main () {
	int maxnumber =0;
	int i;
	int x;
	scanf("%d",&maxnumber) ;
	int shuzu[maxnumber];
	for (i=0;i < maxnumber;i++){
		shuzu[i]=1;
	}
	//全部赋值为1 假设每一个都是素数 
	for (x=2; x < maxnumber; x++) //从2开始 假如2是素数 那么所有2的倍数就不是素数，所以比2大的数，只要没被清除就是素数。 
	{
		if(shuzu[x]){
			for ( i=2; i*x < maxnumber ; i++){
				shuzu[i*x]=0;
			}
		} 
	}
	for (i=2; i < maxnumber; i++){
		if (shuzu[i])
		printf("%d\t",i);
	}


return 0;
}

