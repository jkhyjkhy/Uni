#include <stdio.h>
#include <stdlib.h>


//���� ���Ḯ��Ʈ ����

typedef int element;

typedef struct LISTNODE {
	element data;
	struct	LISTNODE *link;
}LISTNODE;

LISTNODE* add_node(LISTNODE *head, element num)
{
	LISTNODE *newnode = (LISTNODE*)malloc(sizeof(LISTNODE));
	newnode->data = num;
	if (head == NULL) {
		head = newnode;
		newnode->link = head;
	}
	else {
		newnode->link = head->link;
		head->link = newnode;
		head = newnode;
	}
	return head;
}

LISTNODE *search_list(LISTNODE *head, element x) {
	LISTNODE *p = head;

	do {
		if (p->data == x)
			return p; // �߽߰� �߰��� ��� ���� 
		else
			p = p->link;
	} while (p != head);

	return NULL; //Ž�� ����
}

void print_list(LISTNODE *head)
{
	LISTNODE *p;

	if (head == NULL)
		return;
	p = head->link;
	do
	{
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data);
}


int main(void)
{
	int menu = 0;
	int x = 0;
	int num = 0;
	LISTNODE *head = NULL;


	while (menu != 3)
	{
		printf("\n---------------------Menu Bar----------------------\n\n");
		printf("1 : ���ο� ���� ������ �߰�\n");
		printf("2 : ���Ḯ��Ʈ ���ο��� ������ Ž��\n");
		printf("3 : ���α׷� ����\n");
		printf("���ϴ� �޴��� �Է��ϼ��� : ");
		scanf("%d", &menu);
		printf("-----------------------------------------------------\n\n");

		switch (menu)
		{
		case 1:
			printf("������ ���ڸ� �Է��ϼ��� : ");
			scanf("%d", &x);
			head = add_node(head, x);
			printf("��尡 �߰��Ǿ����ϴ� �߰��� ���� : %d\n\n", x);
			print_list(head);
			break;
		case 2:
			printf("Ž���� �����͸� �Է��ϼ��� :");
			scanf("%d", &num);
			search_list(head, num);
			if (search_list(head, num) != NULL)
				printf("����Ʈ���� %d�� ã�ҽ��ϴ�. \n", num);
			else
				printf("����Ʈ���� %d�� ã�� ���߽��ϴ�. \n", num);
			break;
		default:
			printf("�޴��� �����ϴ� ���ڸ� �Է� �����մϴ�!\n");
			break;
		}

	}

	return 0;
}