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
	//ȫ����ֵΪ1 ����ÿһ���������� 
	for (x=2; x < maxnumber; x++) //��2��ʼ ����2������ ��ô����2�ı����Ͳ������������Ա�2�������ֻҪû��������������� 
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

