/*�ַ�����ÿ����ĸ���ֵĴ�����
��ʹ�����º���ͷ��д�����������ַ�����ÿ����ĸ���ֵĴ�����
void count(const char s[], int counts[])
counts��һ����26��Ԫ�ص��������顣const[0]��const[1]������const[25]�ֱ��¼a��b������z���ֵĴ�������ĸ���ִ�Сд��������ĸA����ĸa��������a��*/
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
