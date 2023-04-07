#include<stdio.h>
#include<stdint.h>
int main () {


 int i=0;
 char str[1000]="\0";
 gets(str);
 while(str[i]!='c'&&i<1000);
 { 
  i++;
 }
 if(i==999)
 {
  printf("NO");
 }
 while(str[i]!='u'&&i<1000);
 {
  i++;
 }
 if(i==999)
 {
  printf("NO");
 }
 while(str[i]!='g'&&i<1000);
 {
  i++;
 }
 
 if(i==999)
 {
  printf("NO");
 } 
 while(str[i]!='a'&&i<1000);
 {
  i++;
 }
 
 if(i==999)
 {
  printf("NO");
 }
 while(str[i]!='c'&&i<1000);
 {
  i++;
 }
 
 if(i==999)
 {
  printf("NO");
 }
    while(str[i]!='m'&&i<1000);
 {
  i++;
 }
 
 if(str[i]=='m')
 {
  printf("YES");
 }
 else
 {
   printf("NO");
 }
 return 0;
}





