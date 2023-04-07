#include<stdio.h>
#include<stdlib.h>
typedef struct seq_queue{
	int *shuzu;
	int front;
	int rear;
};
seq_queue* InitQueue(int n);
void EnterQueue(seq_queue* q, int data);
void DeleteQueue(seq_queue* q);
int main(){
	int length, temp=0;
	int cnt = 2;
	printf("please input the length of array:\n");
	scanf("%d", &length);
	seq_queue* queue = InitQueue(length);
	EnterQueue(queue, 1);
	EnterQueue(queue, 1);
	while(cnt<length+2)
	{
		if(cnt<length)
		{
			temp = queue->shuzu[queue->front]+queue->shuzu[queue->front+1];
			EnterQueue(queue, temp);
		}
		printf("%d ", queue->shuzu[queue->front]);
		DeleteQueue(queue);
		cnt++;
	}
	return 0;
}
seq_queue* InitQueue(int n){
	seq_queue *Q = (seq_queue*)malloc(sizeof(seq_queue));
	Q->shuzu = (int *)malloc(sizeof(int)*n);
	Q->front = 0;
	Q->rear = 0;
	return Q;
}
void EnterQueue(seq_queue* q, int data){
	int n = sizeof(q->shuzu);
	if((q->rear+1)%n == q->front)
	{
		printf("The queue is full.");
		return;
	}
	q->shuzu[q->rear] = data;
	q->rear = (q->rear+1)%n;
}
void DeleteQueue(seq_queue* q){
	int n = sizeof(q->shuzu);
	if(q->front == q->rear)
	{
		printf("The queue is empty.");
		return;
	}
	q->front = (q->front+1)%n;
}
