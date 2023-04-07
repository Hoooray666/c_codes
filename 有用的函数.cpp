#include<stdio.h>
#include<stdint.h>
int main () {
	




return 0;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b, *b = t;
}


int cmp(const void* _a, const void* _b) {
    int a = *(int*)_a, b = *(int*)_b;
    return a - b;
}

qsort(nums, numsSize, sizeof(int), cmp);


void sort(char *a[],int length)//对字符指针数组进行排序 
{
	char *tempPtr;
	int i,j,min;//选择排序
	for(i=0;i<=length-2;i++)
	{
		min=i;
		for(j=i+1;j<=length-1;j++)
		{
			if(strcmp(a[min],a[j])>0)
			  min=j;
		}
		if(min!=i)
		{
			tempPtr=a[i];
			a[i]=a[min];
			a[min]=tempPtr;
		}
	 } 
}

void pai(int m[],int n){ //冒泡排序 
    int c;
    for (int i = 1; i <n ; i++) {
        for (int j = 0; j <n-i ; j++) {
            if (m[j]<m[j+1]){
                c=m[j];
                m[j]=m[j+1];
                m[j+1]=c;
            }
        }
    }
}
int length(struct ListNode* head){
    int len =0;
    while(head!=NULL){
        head=head->next;
        len++;
    }
    return len;
}

int length (struct ListNode* head){
    int len=0;
    if(head==NULL){
        return 0;
    }
    return length(head->next)+1;
}

struct ListNode* mysort(struct ListNode* head){ // 冒泡排序 
    int cnt=0;
    struct ListNode*fast;
    struct ListNode*slow;
    fast=head;
    slow=NULL;
    while(fast!=slow){
        while(fast->next!= slow){
            if(fast->val > fast->next->val){
                int tmp;
                tmp = fast->val;
                fast->val = fast->next->val;
                fast->next ->val=tmp;
            }
            fast=fast->next;
        }
        slow = fast;
        fast = head;
    }
    printf("%d" , cnt++);
    return head;
}


struct ListNode* selectsort(struct ListNode* head)  // 选择排序 
{
	struct ListNode*fast=NULL,
	struct ListNode*slow=NULL,
	struct ListNode*end=NULL;
    fast=head;
	slow=head;
	int temp;
    while(fast != end)          //外循环 slow 循环也就是原本选择排序的i 
	{
        while(fast->next != end)//内循环 fast循环也就是原本选择排序的j 
		{
            if(slow->val > fast->next->val) //先把假设当前最小的是slow在的位置 然后让slow成为最小的 
			{
                temp=slow->val;  
                slow->val=pfirst->next->val;
                fast->next->val=temp;
            }
            fast=fast->next;
        }
		slow=slow->next;
        fast=slow;
    }
	return head;
} 
int get(struct ListNode* head,int n ){
    struct ListNode* q;
    q=head;
    for(int i=0;i<n-1;i++){
        q=q->next;
    }
    return q->val;
}
//反转链表俩函数 
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
//求中点

struct ListNode* getmid (struct ListNode* head){
	struct ListNode* fast=head;
    struct ListNode* slow =head;
    while(fast!=NULL || fast->next != NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    if(fast!=NULL){
        slow =slow->next;
    }
    return  slow;
}

struct ListNode* reverseList(struct ListNode* head) {// 反转 
    if (head == null || head->next == null)
        return head;
    ListNode *reverse = reverseList(head->next);
    head->next->next = head;
    head->next = null;
    return reverse;
}









 

