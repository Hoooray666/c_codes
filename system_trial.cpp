#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
void int2string(int b, char *c);
int reverse(char *a,int len);
char* toString(int iVal);
int main () {
	char * str1 = "taskkill /pid ";
	char * str2;
	str2 = toString(19232);
	printf("%s",str2);
	char * shuzu = (char*)malloc(strlen(str1)+strlen(str2));
	strcpy(shuzu,str1);
	strcat(shuzu,str2);
	for(int i =0 ;i< strlen(shuzu)+1;i++){
		printf("%c",shuzu[i]);
	}



return 0;
}

char* toString(int iVal)
   {
       /* �Ż���:
       *  1,��ͨ����ջ�ķ�ʽ,�������ջ,�����Ƕ��ַ�����������,ֱ��ͨ��ָ������,�ڴ濽����ʽ�������ս��
  7      */ 
       char str[1024] = {'\0',};
     char *pos = NULL;
      int sign = 0;   //���� ������ 0
  
     int abs = iVal;
  
      pos = str + 1023; //�ƶ�ָ��,ָ���ջ�ײ�
      *pos-- = '\0';  //end
 
      if(iVal < 0)
      {
          sign = 1;
          abs = -abs;
      }
      
      int dit = 0;
      while(abs > 0)
      {
          dit = abs % 10;
          abs = abs / 10;
  
          *pos-- = (char)('0' + dit); 
      }
  
      if(sign)
          *pos-- = '-';
  
      char *ret = (char*)malloc(1024 - (pos - str));
  
      if(iVal == 0)               //0��һ������
          strcpy(ret, "0");
      else                        //iVal��0�Ŀ���
          strcpy(ret, pos+1);
  
      return(ret);    
 }
  


