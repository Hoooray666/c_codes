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
	int length_a ,length_b,length_c;
	scanf("%d",&length_a);
	ListNode*head_a = create(length_a);
	show(head_a,length_a);
	printf("please input length of B:");
	scanf("%d",&length_b);
	ListNode*head_b = create(length_b);
	show(head_b,length_b);
	printf("please input length of C:");
	scanf("%d",&length_c);
	ListNode*head_c = create(length_c);
	show(head_c,length_c);
	// 不妨让数据为0-20；
	int shuzu[20];
	memset(shuzu,0,sizeof(shuzu));
	ListNode*p =head_b;
	while(p!= NULL){
		shuzu[p->val] ++;
		if(p->next == NULL){
			break;
		}
		p = p->next;
	}
	ListNode* q =head_c;
	while(q != NULL){
		shuzu[q->val] ++;
		if(q->next == NULL){
			break;
		}
		q = q->next;
	}
	p = head_a;
	while(p != NULL){
		if(shuzu[p->val] == 2){
			if(p ->next == NULL){
				length_a--;
				p = NULL;
				continue;
			}
			ListNode* q =p->next->next;
			p->val = p->next->val;
			free(p->next); 
			p->next = q;
			length_a --; 
			continue;
		}
		if(p->next == NULL){
			break;
		}
		p = p->next;
	}
//	for(int i =0;i<20;i++){
//		printf("%d\n",shuzu[i]);
//	}
	show(head_a,length_a);
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


