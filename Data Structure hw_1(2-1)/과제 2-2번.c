#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_STACK 2

typedef int element;

typedef struct {
	int space[MAX_SIZE_STACK];
	int top;
}StackType; // ������ ����ü��

void init_Stack(StackType *s)
{
	s->top = -1;
} // ������ ���� �޸𸮷� �Ҵ�

int is_empty(StackType *s)
{
	return (s->top==-1);
} // ���� �˻� �Լ�

int is_full(StackType *s)
{
	return (s->top == (MAX_SIZE_STACK - 1));
} // ��ȭ �˻� �Լ�

void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr,"������ �����մϴ�.");
		return;
	}
	s->space[++(s->top)] = item;

} // Ǫ�� �Լ�

element pop(StackType *s)
{
	if (is_empty(s)) {
		printf("����");
		exit(1);
	}
	else
		return s->space[(s->top)--];
} // �� �Լ�




int main(void)
{
	StackType s;
	init_Stack(&s);

	int n = 0;
	
	push(&s, 1);
	push(&s, 0);

	printf("�� ���α׷��� �������� �Ͽ��� �Էµ� ���������� �Ǻ���ġ ������ ����մϴ�. ù�װ� ��°���� ���� 0�� 1 �Դϴ�.\n ������ �ϳ� �Է��ϼ��� : ");
	scanf("%d", &n);
	printf("%d %d ", 0, 1);
	for (int i = 3;i <= n;i++)
	{
		int top = pop(&s);
		int bottom = pop(&s);
		int fib = top + bottom;
		printf("%d ", fib);
		push(&s, fib);
		push(&s, bottom);
	}
	return 0;
}
