#include <stdio.h>
#include <stdlib.h>


//원형 연결리스트 예제

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
			return p; // 발견시 발견한 노드 리턴 
		else
			p = p->link;
	} while (p != head);

	return NULL; //탐색 실패
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
		printf("1 : 새로운 노드와 데이터 추가\n");
		printf("2 : 연결리스트 내부에서 데이터 탐색\n");
		printf("3 : 프로그램 종료\n");
		printf("원하는 메뉴를 입력하세요 : ");
		scanf("%d", &menu);
		printf("-----------------------------------------------------\n\n");

		switch (menu)
		{
		case 1:
			printf("기입할 숫자를 입력하세요 : ");
			scanf("%d", &x);
			head = add_node(head, x);
			printf("노드가 추가되었습니다 추가된 숫자 : %d\n\n", x);
			print_list(head);
			break;
		case 2:
			printf("탐색할 데이터를 입력하세요 :");
			scanf("%d", &num);
			search_list(head, num);
			if (search_list(head, num) != NULL)
				printf("리스트에서 %d를 찾았습니다. \n", num);
			else
				printf("리스트에서 %d를 찾지 못했습니다. \n", num);
			break;
		default:
			printf("메뉴에 존재하는 숫자만 입력 가능합니다!\n");
			break;
		}

	}

	return 0;
}