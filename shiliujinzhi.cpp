#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
int main () {
	int i,j;
	i=j=0;
	int cnt=0;
	int p;
	int shuzu1[150]={0};
	char shuzu[150]={'0'};
//	scanf("%s",shuzu);
gets(shuzu);
	while(shuzu[i]!='\0'){
		if(shuzu[i]=='x'){
			i++;
			shuzu1[j]+=(shuzu[i]-'0')*16;
			p=shuzu1[j];
			if(shuzu[i+1]>='a' && shuzu[i+1]<= 'f'){
				shuzu1[j]+=(shuzu[i+1]-'a')+10;
			}
			else if(shuzu[i+1]>='0' && shuzu[i+1]<= '9'){
				shuzu1[j]+=(shuzu[i+1]-'0');
			}
//			printf("%d\n",shuzu1[j]-p);
			j++;
			i+=2; 
			cnt++;
		}
		i++;
	} 
//	int shuzu2[30]={55 , 56 , 54 , 79 , 115 , 69 , 114 , 116 , 107 , 49 , 50};
	for(int k=0 ;k<30;k++){
		printf("%c",shuzu1[k]);
	}
//	printf("%c",44);





return 0;
}

