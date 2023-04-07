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
       /* 优化点:
       *  1,不通过堆栈的方式,无需进出栈,或者是对字符串进行逆序,直接通过指针运算,内存拷贝方式或者最终结果
  7      */ 
       char str[1024] = {'\0',};
     char *pos = NULL;
      int sign = 0;   //正数 或者是 0
  
     int abs = iVal;
  
      pos = str + 1023; //移动指针,指向堆栈底部
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
  
      if(iVal == 0)               //0的一个处理
          strcpy(ret, "0");
      else                        //iVal非0的拷贝
          strcpy(ret, pos+1);
  
      return(ret);    
 }
  


