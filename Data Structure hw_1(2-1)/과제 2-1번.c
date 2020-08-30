#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct {
	element  queue[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;
//

int i = 0; //�˻� �Լ��� ������ �ϱ� ���� ������ �������� i ����

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}//������ �޽��� ���

void init(QueueType *q)
{
	q->front = q->rear = 0;
}// �ʱ�ȭ �Լ�

int is_empty(QueueType *q)
{
	return i == 0;
}// ���� �˻� �Լ�

int is_full(QueueType *q)
{
	return i == MAX_QUEUE_SIZE;
}// ��ȭ �˻� �Լ�

void enqueue(QueueType *q, element item)
{
	++i;
	if (is_full(q))
		printf("��ȭ�����Դϴ�");
	q->rear = (q->rear + 1);
	q->queue[q->rear] = item;
} // ���� �Լ�


element dequeue(QueueType *q)
{
	--i;
	if (is_empty(q))
		printf("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
} // ���� �Լ�

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
} // �Է¹��� ������ ���� �Ǻ���ġ �Լ�


int main(void)
{
	int size = 0;
	printf("�� ���α׷��� n������ �Ǻ���ġ ������ �����մϴ�. �Ѱ��� ������ �Է��ϼ��� :");
	scanf("%d", &size);
	for (int n = 1; n <= size;n++) 
	{
		printf("n=%d�� ���� �Ǻ���ġ �� : %d\n", n,Fib(n));
	}
	return 0;
} // ���� �Լ�
