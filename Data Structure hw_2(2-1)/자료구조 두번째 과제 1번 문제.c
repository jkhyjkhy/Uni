#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
typedef int element;

typedef struct LISTNODE { //구조체 선언
	element data;
	struct LISTNODE *link;
}LISTNODE;

int num[MAX_SIZE] = { 0 };

void printf_list(LISTNODE *head) // 연결리스트의 처음부터 NULL 포인터를 만날때까지 출력하는 함수
{
	for (LISTNODE *p = head;p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("\n");
}
LISTNODE *create(element data) // 노드 생성 함수
{
	LISTNODE *firstnode = (LISTNODE*)malloc(sizeof(LISTNODE));

	firstnode->link = NULL;
	firstnode->data = data;

	return firstnode;
}

void add_node(LISTNODE **head, element data) // 노드 추가 함수
{
	LISTNODE *newnode = create(data);

	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		LISTNODE * cur = *head;

		while (cur->link != NULL)
		{
			cur = cur->link;
		}

		cur->link = newnode;
	}
}


void split(int input_size,LISTNODE *A, LISTNODE **BB, LISTNODE **CC, LISTNODE **DD) //스플릿 함수
{
	LISTNODE *temp = A;
	LISTNODE *b = NULL;
	LISTNODE *c = NULL;
	LISTNODE *d = NULL;
	

	for (int count = 1;count <= input_size; count++)
	{
		if (count % 3 == 1 && b == NULL) {
			b = create(temp->data);
			temp = temp->link;
		}
		else if (count % 3 == 1) {
			add_node(&b, temp->data);
			temp = temp->link;
		}
		else if (count % 3 == 2 && c == NULL) {
			c = create(temp->data);
			temp = temp->link;
		}
		else if (count % 3 == 2) {
			add_node(&c, temp->data);
			temp = temp->link;
		}
		else if (count % 3 == 0 && d == NULL) {
			d = create(temp->data);
			temp = temp->link;
		}
		else if (count % 3 == 0) {
			add_node(&d, temp->data);
			temp = temp->link;
		}

	}
	*BB = b;
	*CC = c;
	*DD = d;

}

void freeNodes(LISTNODE* p) { //노드 제거 함수

	LISTNODE *temp;
	while (p != NULL)
	{
		temp = p;
		p = p->link;
		free(temp);
	}
}

int main(void) //메인함수
{

	int input_size = 0;
	

	LISTNODE *A = NULL;
	LISTNODE *B = NULL;
	LISTNODE *C = NULL;
	LISTNODE *D = NULL;



	printf("원하는 노드의 총 개수를 입력하십시오 (단, 최대 노드의 갯수는 1000개 입니다.) :");
	scanf("%d", &input_size);	
	
		for (int i = 0; input_size > i;i++)
		{
			if (A == NULL) {
				printf("먼저 A 노드의 헤드에 데이터를 추가해 주십시오(%d개의 데이터가 남았습니다) :",input_size-i);
				scanf("%d", &num[i]);

				A = create(num[i]);
		    } 
			else 
			{
				printf("데이터를 추가해 주십시오(%d개의 데이터가 남았습니다.):", input_size - i);
				scanf("%d", &num[i]);

				add_node(&A, num[i]);
			}
	    }
		

	split(input_size,A, &B, &C, &D);
	printf("A :");
	printf_list(A);
	printf("\nB : ");
	printf_list(B);
	printf("\nC :");
	printf_list(C);
	printf("\nD : ");
	printf_list(D);

	freeNodes(A);
	freeNodes(B);
	freeNodes(C);
	freeNodes(D);

	return 0;
}