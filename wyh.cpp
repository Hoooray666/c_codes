/*字符串中每个字母出现的次数：
请使用如下函数头编写函数，数出字符串中每个字母出现的次数。
void count(const char s[], int counts[])
counts是一个有26个元素的整数数组。const[0]，const[1]，…，const[25]分别记录a，b，…，z出现的次数。字母不分大小写，例如字母A和字母a都被看作a。*/
#include <iostream>
#include <string.h>
using namespace std;
void count(const char s[], int counts[])
{
 int len=strlen(s);
// const char *p;
// for(p=s;*p<=s[len];p++)
// {
//  if(*p=='a')
//  counts[0]++;
//  if(*p=='b')
//  counts[1]++;
//  if(*p=='c')
//  counts[2]++;
//  if(*p=='d')
//  counts[3]++;
//  if(*p=='e')
//  counts[4]++;
//  if(*p=='f')
//  counts[5]++;
//  if(*p=='g')
//  counts[6]++;
//  if(*p=='h')
//  counts[7]++;
//  if(*p=='i')
//  counts[8]++;
//  if(*p=='j')
//  counts[9]++;
//  if(*p=='k')
//  counts[10]++;
//  if(*p=='l')
//  counts[11]++;
//  if(*p=='m')
//  counts[12]++;
//  if(*p=='n')
//  counts[13]++;
//  if(*p=='o')
//  counts[14]++;
//  if(*p=='p')
//  counts[15]++;
//  if(*p=='q')
//  counts[16]++;
//  if(*p=='r')
//  counts[17]++;
//  if(*p=='s')
//  counts[18]++;
//  if(*p=='t')
//  counts[19]++;
//  if(*p=='u')
//  counts[20]++;
//  if(*p=='v')
//  counts[21]++;
//  if(*p=='w')
//  counts[22]++;
//  if(*p=='x')
//  counts[23]++;
//  if(*p=='y')
//  counts[24]++;
//  if(*p=='z')
//  counts[25]++;
//  }
	counts = {0};
	int cnt =0;
	for(int i =0;i<len;i++){
		cnt= s[i] - 'a';
		counts[cnt] ++;
		cnt =0;
	} 
  for(int i=0;i<26;i++)
        if(counts[i]!=0)
        cout<<":"<<counts[i]<<"times"<<endl;
}
int main()
{
 char s[60];
    int counts[26];
 cout<<"Enter a string:";
 gets(s);
 strlwr(s);
 count(s,counts);
    return 0;
 
}
