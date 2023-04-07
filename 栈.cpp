#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100 
typedef char datatype;
typedef int status;//定义状态 
using namespace std;
typedef struct{
    datatype *base;
    datatype *top;
    int size;
}stack;

status initstack(stack &s)
{
 s.base=new datatype[MAXSIZE];//为栈分配一个新的内存空间 
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
    *s.top=e;                //把e赋给top指针指向地址的值 
    s.top++;                 //将top指针上移一位 
    return 1;
}

char pop(stack &s,datatype &e)
{
 if(s.base==s.top) 
     return 0;
 else
     s.top--;             //将top指针下移一位
     e=*s.top;
}

status traverse(stack &s)
{
 datatype *p;             //新建一个遍历的指针 
 if(s.top==s.base)
 {
  cout<<"stack is null"<<endl; 
     return 0;
 }
 else
 {
  p=s.top;            //p初始指向top指针指向的地址 
  while(p>=s.base)
  {
   cout<<*p<<" ";
   p--;            //p指向的地址向下移 
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
     
