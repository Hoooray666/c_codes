#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack{
	int size;
	char *top;
	char *base;
};
Stack* creatstack();
char getTop(Stack *s1);
void push(Stack *s1, char a);
void pop(Stack *s1);
int main(){
	char shuzu[100];
	char top;
	int i=0;
	Stack *s = creatstack();
	scanf("%s", shuzu);
	int length = strlen(shuzu);
	for(i=0;i<length;i++){
		if(shuzu[i]=='('||shuzu[i]=='<'||shuzu[i]=='['){
			push(s, shuzu[i]);
		}
		else{
			if(s->base == s->top){
				printf("The parentheses do not match!\n");
				return 0;
			}
			else{
				top = getTop(s);
				pop(s);
				if(shuzu[i]==')' && top!='('){
					printf("The parentheses do not match!\n");
					return 0;
				}
				else if(shuzu[i]=='>' && top!='<'){
					printf("The parentheses do not match!\n");
					return 0;
				}
				else if(shuzu[i]==']' && top!='['){
					printf("The parentheses do not match!\n");
					return 0;
				}
			}
		}
	}
	if(s->base == s->top){
		printf("The match is successful!\n");
		return 0;
	}
	else{
		printf("The parentheses do not match!\n");
		return 0;
	}
} 

Stack* creatstack(){
	Stack* s1 = (Stack *)malloc(sizeof(Stack));
	s1->base = (char *)malloc(sizeof(char));
	s1->top = s1->base;
	s1->size = 100;
	return s1;
}

char getTop(Stack *s1){
	if(s1->top == s1->base)
	{
		printf("The stack is empty.\n");
		return 0;
	}
	char p = *(s1->top-1);
	return p;
}

void push(Stack *s1, char a){
	if(s1->top - s1->base >= s1->size)
	{
		printf("The stack is full!");
	}
	*s1->top++ = a;
}

void pop(Stack *s1){
	char s;
	if(s1->base == s1->top)
	{
		printf("The stack is empty.\n");
		return;
	}
	(s1->top--);
}
