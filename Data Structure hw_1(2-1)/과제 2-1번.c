#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct {
	element  queue[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;
//

int i = 0; //검사 함수를 간단히 하기 위해 정수형 전역변수 i 설정

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}//에러시 메시지 출력

void init(QueueType *q)
{
	q->front = q->rear = 0;
}// 초기화 함수

int is_empty(QueueType *q)
{
	return i == 0;
}// 공백 검사 함수

int is_full(QueueType *q)
{
	return i == MAX_QUEUE_SIZE;
}// 포화 검사 함수

void enqueue(QueueType *q, element item)
{
	++i;
	if (is_full(q))
		printf("포화상태입니다");
	q->rear = (q->rear + 1);
	q->queue[q->rear] = item;
} // 삽입 함수


element dequeue(QueueType *q)
{
	--i;
	if (is_empty(q))
		printf("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
} // 삭제 함수

int Fib(int size) {
	QueueType q;
	init(&q);
	int sum = 1;
	enqueue(&q, 0);
	enqueue(&q, sum);
	for (int i = 1; i <= size; i++) {
		sum = dequeue(&q) + sum;
		enqueue(&q, sum);
	}
	return dequeue(&q);
} // 입력받은 정수에 대한 피보나치 함수


int main(void)
{
	int size = 0;
	printf("본 프로그램은 n까지의 피보나치 수열을 나열합니다. 한개의 정수를 입력하세요 :");
	scanf("%d", &size);
	for (int n = 1; n <= size;n++) 
	{
		printf("n=%d에 대한 피보나치 수 : %d\n", n,Fib(n));
	}
	return 0;
} // 메인 함수
