#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_STACK 50

typedef int element;

typedef struct {
	element *data;
	int capacity;
	int top;
}StackType; // ������ ����ü��

void init_Stack(StackType *s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element *)malloc(s->capacity * sizeof(element));
} // ������ ���� �޸𸮷� �Ҵ�

int is_empty(StackType *s)
{
	return (s->top == -1);
} // ���� �˻� �Լ�

int is_full(StackType *s)
{
	return (s->top == (s->capacity - 1));
} // ��ȭ �˻� �Լ�

void push(StackType *s, element item)
{
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
	} 
	s->data[++(s->top)] = item;

} // Ǫ�� �Լ�

element pop(StackType *s)
{
	if (is_empty(s)) {
		printf("����");
		exit(1);
	}
	else
		return s->data[(s->top)--];
} // �� �Լ�

int main(void)
{
	int i = 0;
	int SIZE = 0;
	StackType s;
	init_Stack(&s);

	printf("���� �迭�� ũ�� : ");
	scanf("%d", &SIZE);

	if (SIZE > MAX_SIZE_STACK)
		do {
			printf("�迭�� ũ��� 50���� \n");
			printf("������ �Է��Ͻÿ� : ");
			scanf("%d", &SIZE); //����ڰ� 50 �̻��� �迭 ũ�⸦ �Է����� ���
		} while (SIZE > MAX_SIZE_STACK);

		printf("������ �Է��Ͻÿ� : ");

		for (i = 0; i < SIZE; i++)
		{
			int num;
			scanf("%d", &num);
			push(&s, num);
		} // ������ �Է¹޾� ���ÿ� ����

		printf("������ : ");

		for (i = 0; i < SIZE; i++)
		{
			printf("%d ", pop(&s));
		} // ������ ���ÿ��� �ϳ��� ���� �����ŭ �迭

		free(s.data); // ���� �޸� free
		return 0;

}