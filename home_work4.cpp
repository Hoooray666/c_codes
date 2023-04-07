// Created on Francis’s iPad.

#include <stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>

struct  ListNode{
   int val;
   struct ListNode *next;
};
void show(struct ListNode* head ,int length);
struct ListNode* create(int length);
int main() {
    printf("please input the lenth of struct ListNode:");
    int length_a,mink,maxk;
    scanf("%d",&length_a);
    struct ListNode* head = create(length_a);
    show(head,length_a);
    printf("input mink and maxk:");
    scanf("%d %d",&mink,&maxk);
    struct ListNode*p = head;
    struct ListNode*q = head;
    while(p != NULL ){
        if(p->val <= mink && p->next -> val>mink){
            break;
        }
        if(p -> next == NULL){
            break;
       }
       p = p->next;
    }
    while(q != NULL){
		if(q->val < maxk && q->next->val >= maxk){
			break;
    	}
      	if(q->next == NULL){
    		break;
      	}
      	q = q-> next;
    }
    ListNode* n = p ;
    while(n->next != q){
    	free(n);
    	n = n->next;
	}
	p->next = q->next;
    printf("[ %d",head->val);
    head = head ->next;
    while(head != NULL){
        printf(" , %d",head->val);
        if(head -> next ==NULL){
            break;
        }
        head = head -> next;
    }
    printf(" ]\n");
}

void show(struct ListNode* head , int length){
   printf("[ %d",head->val);
   head = head ->next;
   for(int i=1;i<length;i++){
      printf(" , %d",head->val);
      head = head ->next;
   }
   printf(" ]\n");
}

struct ListNode * create(int length){
    struct ListNode* head = (struct ListNode*) malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p = head ;
	for(int i =0;i<length;i++){
		struct ListNode* s = (struct  ListNode*)malloc(sizeof(struct ListNode));
      scanf("%d",&s->val);
      p ->next = s;
      s ->next = NULL;
      p = s;
   }
   return head -> next;
}
