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
void min_and_max(ListNode*head,int*min,int*max);
int main () {
	printf("please input length of A:");
	int length_a ,length_b;
	scanf("%d",&length_a);
	ListNode*head_a = create(length_a);
	show(head_a,length_a);
	printf("please input length of B:");
	scanf("%d",&length_b);
	ListNode*head_b = create(length_b);
	show(head_b,length_b);
	// 不妨让数据为0-20；
	int shuzu[20];
	memset(shuzu,0,sizeof(shuzu));
	ListNode*p = (ListNode*) malloc(sizeof(ListNode));
	p= head_a;
	int cnt = 0;
	while(p!= NULL){
		if(shuzu[p->val] == 1){
			p = p->next;
			continue;
		}
		shuzu[p->val] ++;
		if(p->next == NULL){
			break;
		}
		p = p->next;
	}
	ListNode*q = head_b;
	while(q != NULL){
		shuzu[q->val] ++;
		if(q->next == NULL){
			break;
		}
		q = q->next;
	}
	for(int i =0;i<20;i++){
		printf("%d\n",shuzu[i]);
	}
	ListNode*n = (ListNode*) malloc(sizeof(ListNode));
	n = p;
	for(int i=0;i<20;i++) {
		if(shuzu[i] == 2){
			printf("shuzu[%d] = %d\n",i,shuzu[i]);
			cnt++;
			ListNode*s = (ListNode*) malloc(sizeof(ListNode));
			s->val = i;
			n ->next = s;
			s->next =NULL;
			n = s;
		}
	}
	show(p->next,cnt);



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

void min_and_max(ListNode*head,int*min,int*max){
	while(head != NULL){
		if(head->val < *min){
			*min = head->val;
		}
		else if(head->val > *max){
			*max = head->val;
		}
		if(head->next == NULL){
			break;
		}
		head = head->next;
	}
}


