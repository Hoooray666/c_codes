#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h> 
typedef struct ListNode {
    int val;
    struct ListNode *next;
};
void show(ListNode* head,int length);
ListNode* create(int length);
int main () {
	printf("please input length of A:");
	int length_a ,x;
	scanf("%d",&length_a);
	ListNode*head_a = create(length_a);
	show(head_a,length_a);
	printf("please input the  number yo want to insert:");
	scanf("%d",&x);
	ListNode* pre =head_a ;
	int flag = 0;
	ListNode*p =(ListNode*)malloc(sizeof(ListNode));
	ListNode *q =(ListNode*)malloc(sizeof(ListNode));
	if(x<= pre->val){
//		printf("666");
		p->val = head_a ->val;
		head_a->val = x;
		p->next = head_a->next;
		head_a ->next = p;
		show(head_a,length_a+1);
		return 0;
	}
//	return 0;
	p = head_a->next;
	while(p != NULL){
		if(x <= p->val){
			q->val =x;
			pre->next = q;
			q->next = p;
			flag =1;
			break;
		}
		pre = p;
		if(p -> next == NULL){
//			flag =1;
			break;
		}
		p = p->next;
	}
	if(flag ==0){
		p->next = q;
		q->val = x;
	}
	show(head_a,length_a+1);
return 0;
}

void show(ListNode* head,int length){
	printf("[ %d",head->val);
	head = head -> next;
	for(int i =1; i<length ;i++){
		
		printf(" , %d",head->val);
		head = head -> next;
		
	}
	printf(" ]\n");
}

ListNode* create(int length){
	ListNode * head = (ListNode*) malloc(sizeof(ListNode));
	head->next = NULL;
	ListNode * p;
	p = head;
	for(int i =0;i<length;i++){
		ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
		scanf("%d",&s->val);
		p->next = s;
		s->next = NULL;
		p = s;
	}
	return head->next;
}
