#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

struct Listnode {
    int val;
    struct Listnode *next;
};

void shuchu(struct Listnode* head);
Listnode* deletee(Listnode* head);
int main () {
	int n=0;
	scanf("%d",&n);
	getchar();
	struct Listnode* head = (struct Listnode*)malloc(sizeof(struct Listnode)*n);
//	struct Listnode* head;
	head->next =NULL;
	struct Listnode*p = (struct Listnode*)malloc(sizeof(struct Listnode));
//	struct Listnode* s;
	p= head;
	int i=0;
	char a;
//	scanf("%s",&a);
head->val =1;
	a= getchar();
//	p->val =a-'0';
//	a=getchar();
	while(a != '\n'){
		struct Listnode*s = (struct Listnode*)malloc(sizeof(struct Listnode));
//		scanf("%s",&a);
		s->val =a-'0';
		p->next =s;
		s->next =NULL;
		p=s;
		a= getchar();
		if( a == ' '){
			a= getchar();
		}
//		printf("%d",s->val);
//		i++;
	}
	
//	printf("%d",head->val);
	shuchu(head);
	printf("·Ö½çÏß\n"); 
//	Listnode *b =deletee(head);
//	shuchu(b);
	shuchu(head->next);
return 0;
}
void shuchu(struct Listnode* head){
	struct Listnode* q;
	q=head;
//	if(head==NULL){
//		printf("%d",head->val);
//	}
//	printf("%d",head->val);
//	printf("%d",1);
//	shuchu(head->next);
	while(q!= NULL){
		printf("%d\n",q->val);
		q=q->next;
	}
}

Listnode* deletee(Listnode* head){
	Listnode*p =head;
	return p->next;
}

