#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30

typedef struct movie{
	char title[SIZE];
	char rating[SIZE];
	char date[SIZE];
	struct movie* link;
}movie;


movie* list = NULL;

void stars3(void);
void stars2(void);
void stars(void);
void add_info(void);
void reset(void);
void movlist(void);
void rating_align(void);


int main(void)
{
	int select=0;
	do
	{
		stars();
		printf("1. 초기화\n");
		printf("2. 영화 추가\n");
		printf("3. 영화 리스트 출력\n");
		printf("4. 영화 평점 정렬\n");
		printf("5. 종료\n");
		stars();
		printf("원하는 메뉴의 번호를 입력하세요 : ");
		scanf("%d", &select);

		switch (select) 
		{
		case 1 :
			reset();
			select = 1;
			break;
		case 2:
			add_info();
			select = 2;
			break;
		case 3:
			printf("\n");
			stars2();
			printf("\n");
			movlist();
			stars3();
			select = 3;
			break;
		case 4:
			rating_align();
			printf("\n");
			stars2();
			printf("\n");
			movlist();
			stars3();
			select = 4;
			break;
		case 5:
		 select = 5;
		    break;
		default:
			printf("메뉴에 등록되어 있는 번호를 입력하세요\n");
		break;
		}
	} while (select != 5);
	return 0;
}

void stars(void)
{
	for (int i = 0; i <= 20; i++)
	{
		printf("=");
	}
	printf("\n");
}

void reset(void)
{
	movie* clear;
	while (list != NULL)
	{
		clear = list->link;
		free(list);
		list = clear;
		printf("이전 영화 정보는 초기화 되었습니다.\n");
	}
	list = NULL;
}

void add_info(void)
{
	movie* newlist = (movie*)malloc(sizeof(movie));

	printf("영화의 이름 : ");
	scanf(" %s", newlist->title);
	printf("영화의 평점 : ");
	scanf(" %s", newlist->rating);
	printf("영화의 개봉일 : ");
	scanf(" %s", newlist->date);
	newlist->link = NULL;

	//printf("이름 : %s\n", newlist->title);
	//printf("번호 : %s\n", newlist->rating);
	//printf("이름 : %s\n", newlist->date); 확인용 이었습니다.

	if (list == NULL)
	{
		list = newlist;
	}
	else
	{
		movie* movieptr = list;
		while (movieptr->link != NULL)
			while (movieptr->link != NULL)
				movieptr = movieptr->link;
		movieptr->link = newlist;
	}
	printf("\n추가되었습니다.\n");
}


void movlist(void)
{
	movie* p = list;
	int i = 1;
		while (p)
		{
			movie* data = p;
			printf("%d %21s %9s %16s\n",i,data->title, data->rating, data->date);
			p = p->link;
			i++;
		}
		/* 기존에 쓸까 생각하던 코드 (data를 빼서 더 줄이 짧음)
		movie* p = list;
		
		while (p)
		{
			printf("%d [%s] %s %s\n",i, p->title, p->rating, p->date);
			p = p->link;
		}*/

		printf("\n");
}

void rating_align(void)
{
	movie* p = list;
	movie* pp;
	movie* get;
	movie* newlist = NULL;

	while (p)
	{
		get = p;
		p = p->link;

		if (newlist == NULL)
		{
			newlist = get;
			newlist->link = NULL;
		}
		else
		{
			pp = newlist;
			if (strcmp(newlist->rating, get->rating) < 0)
			{
				get->link = newlist;
				newlist = get;
			}
			else
			{
				while (pp->link)
				{
					
					if (strcmp(pp->link->rating, get->rating) < 0)
					{
						break;
					}
					pp = pp->link;
				}
				get->link = pp->link;
				pp->link = get;
			}
		}
	}
	list = newlist;

}

void stars2(void)
{
	printf("NO.           영화 제목       평점         개봉일\n");
	for (int i = 0;i <=70;i++)
	{
		printf("=");
	}
	printf("\n");
}
void stars3(void)
{
	for (int i = 0; i <= 70; i++)
	{
		printf("=");
	}
	printf("\n");
}