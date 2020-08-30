#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
typedef int element;

typedef struct LISTNODE { //����ü ����
	element data;
	struct LISTNODE *link;
}LISTNODE;

int num[MAX_SIZE] = { 0 };

void printf_list(LISTNODE *head) // ���Ḯ��Ʈ�� ó������ NULL �����͸� ���������� ����ϴ� �Լ�
{
	for (LISTNODE *p = head;p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("\n");
}
LISTNODE *create(element data) // ��� ���� �Լ�
{
	LISTNODE *firstnode = (LISTNODE*)malloc(sizeof(LISTNODE));

	firstnode->link = NULL;
	firstnode->data = data;

	return firstnode;
}

void add_node(LISTNODE **head, element data) // ��� �߰� �Լ�
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


void split(int input_size,LISTNODE *A, LISTNODE **BB, LISTNODE **CC, LISTNODE **DD) //���ø� �Լ�
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

void freeNodes(LISTNODE* p) { //��� ���� �Լ�

	LISTNODE *temp;
	while (p != NULL)
	{
		temp = p;
		p = p->link;
		free(temp);
	}
}

int main(void) //�����Լ�
{

	int input_size = 0;
	

	LISTNODE *A = NULL;
	LISTNODE *B = NULL;
	LISTNODE *C = NULL;
	LISTNODE *D = NULL;



	printf("���ϴ� ����� �� ������ �Է��Ͻʽÿ� (��, �ִ� ����� ������ 1000�� �Դϴ�.) :");
	scanf("%d", &input_size);	
	
		for (int i = 0; input_size > i;i++)
		{
			if (A == NULL) {
				printf("���� A ����� ��忡 �����͸� �߰��� �ֽʽÿ�(%d���� �����Ͱ� ���ҽ��ϴ�) :",input_size-i);
				scanf("%d", &num[i]);

				A = create(num[i]);
		    } 
			else 
			{
				printf("�����͸� �߰��� �ֽʽÿ�(%d���� �����Ͱ� ���ҽ��ϴ�.):", input_size - i);
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