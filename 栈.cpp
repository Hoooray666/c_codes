#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100 
typedef char datatype;
typedef int status;//����״̬ 
using namespace std;
typedef struct{
    datatype *base;
    datatype *top;
    int size;
}stack;

status initstack(stack &s)
{
 s.base=new datatype[MAXSIZE];//Ϊջ����һ���µ��ڴ�ռ� 
 if(!s.base)
 return 0;
 else
 {
  *(s.base)=0;
  s.top=s.base;
     s.size=MAXSIZE;
     return 1;
 } 
}

status isempty(stack &s)
{
    return s.base==s.top;
}

status size(stack &s)
{
 if(s.base==s.top)
 return 0;
 else
 return s.top-s.base+1;
}

datatype gettop(stack &s)
{
 if(s.base==s.top)
 return 0;
 else
 return *(s.top);
}

status push(stack &s,datatype e)
{
    if(s.top-s.base==s.size)
    {
     cout<<"stack is full"<<endl;
        return 0;
 }
    *s.top=e;                //��e����topָ��ָ���ַ��ֵ 
    s.top++;                 //��topָ������һλ 
    return 1;
}

char pop(stack &s,datatype &e)
{
 if(s.base==s.top) 
     return 0;
 else
     s.top--;             //��topָ������һλ
     e=*s.top;
}

status traverse(stack &s)
{
 datatype *p;             //�½�һ��������ָ�� 
 if(s.top==s.base)
 {
  cout<<"stack is null"<<endl; 
     return 0;
 }
 else
 {
  p=s.top;            //p��ʼָ��topָ��ָ��ĵ�ַ 
  while(p>=s.base)
  {
   cout<<*p<<" ";
   p--;            //pָ��ĵ�ַ������ 
  }
 return 1;
 } 
}

int ins(char ch)
{
 switch(ch){
  case'#':return 0;
  case'(':return 1;
  case'+':return 3;
  case'-':return 3;
  case'*':return 5;
  case'/':return 5;
  case'%':return 5;
  case'^':return 7;
  case')':return 8;
 };
}

int getnum(char &c){
   int num = 0;
   num=static_cast<int>(c-'0');
   return num;
}

int outs(char ch)
{
 switch(ch){
  case'#':return 0;
  case'(':return 8;
  case'+':return 2;
  case'-':return 2;
  case'*':return 4;
  case'/':return 4;
  case'%':return 4;
  case'^':return 6;
  case')':return 1;
 };
}

int operate(int a, char theta, int b){
     switch(theta){
         case '+':
            return a+b;
         case '-':
            return a-b;
         case '*':
            return a*b;
         case '/':
            return a/b;
        }
    }
     
