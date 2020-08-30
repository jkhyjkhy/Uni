#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_STACK 2

typedef int element;

typedef struct {
	int space[MAX_SIZE_STACK];
	int top;
}StackType; // 스택을 구조체로

void init_Stack(StackType *s)
{
	s->top = -1;
} // 스택을 동적 메모리로 할당

int is_empty(StackType *s)
{
	return (s->top==-1);
} // 공백 검사 함수

int is_full(StackType *s)
{
	return (s->top == (MAX_SIZE_STACK - 1));
} // 포화 검사 함수

void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr,"공간이 부족합니다.");
		return;
	}
	s->space[++(s->top)] = item;

} // 푸쉬 함수

element pop(StackType *s)
{
	if (is_empty(s)) {
		printf("에러");
		exit(1);
	}
	else
		return s->space[(s->top)--];
} // 팝 함수




int main(void)
{
	StackType s;
	init_Stack(&s);

	int n = 0;
	
	push(&s, 1);
	push(&s, 0);

	printf("본 프로그램은 스택으로 하여금 입력된 정수까지의 피보나치 수열을 계산합니다. 첫항과 둘째항은 각각 0과 1 입니다.\n 정수를 하나 입력하세요 : ");
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
