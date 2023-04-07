#include<stdio.h>
#include<stdint.h>
int main () {
	char name;
//	scanf("%c", &name);
	name = getchar();
	char shuzu[10];
	int cnt = 0;
	shuzu[0] = name ;
	int i; 
	while ( name != '\n') {
//		scanf("%d", &name);
		name = getchar();
		int det =1;
		if (cnt ==0){
				printf("%c",shuzu[0]);
			}		
		cnt ++;
//		printf("%d\n",name);
		for ( i = 0 ; i< 10 ;i++){
			if ( shuzu[i] == name){
				det =0 ;
				cnt--;
				break;
			}
		}
		if (det == 1){
			shuzu[cnt] = name;
			printf(" %c",shuzu[cnt-1]);		
		}
	}
//	printf("%d \n",cnt);
//	int j;
//	for (j =1 ;j< cnt-1 ; j++){
//		printf(" %c",shuzu[j]);
//	}
return 0;
}

