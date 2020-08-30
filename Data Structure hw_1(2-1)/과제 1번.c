#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_STACK 50

typedef int element;

typedef struct {
	element *data;
	int capacity;
	int top;
}StackType; // 스택을 구조체로

void init_Stack(StackType *s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element *)malloc(s->capacity * sizeof(element));
} // 스택을 동적 메모리로 할당

int is_empty(StackType *s)
{
	return (s->top == -1);
} // 공백 검사 함수

int is_full(StackType *s)
{
	return (s->top == (s->capacity - 1));
} // 포화 검사 함수

void push(StackType *s, element item)
{
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
	} 
	s->data[++(s->top)] = item;

} // 푸쉬 함수

element pop(StackType *s)
{
	if (is_empty(s)) {
		printf("에러");
		exit(1);
	}
	else
		return s->data[(s->top)--];
} // 팝 함수

int main(void)
{
	int i = 0;
	int SIZE = 0;
	StackType s;
	init_Stack(&s);

	printf("정수 배열의 크기 : ");
	scanf("%d", &SIZE);

	if (SIZE > MAX_SIZE_STACK)
		do {
			printf("배열의 크기는 50이하 \n");
			printf("정수를 입력하시오 : ");
			scanf("%d", &SIZE); //사용자가 50 이상의 배열 크기를 입력했을 경우
		} while (SIZE > MAX_SIZE_STACK);

		printf("정수를 입력하시오 : ");

		for (i = 0; i < SIZE; i++)
		{
			int num;
			scanf("%d", &num);
			push(&s, num);
		} // 정수를 입력받아 스택에 저장

		printf("실행결과 : ");

		for (i = 0; i < SIZE; i++)
		{
			printf("%d ", pop(&s));
		} // 정수를 스택에서 하나씩 꺼내 사이즈만큼 배열

		free(s.data); // 동적 메모리 free
		return 0;

}