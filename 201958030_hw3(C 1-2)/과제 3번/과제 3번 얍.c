#include <stdio.h>
#include <string.h>
#define SIZE 20

struct order 
{
	char number[SIZE];
}list[12];

struct professor
{
	char name[SIZE];
	char office[SIZE];
	char phone[SIZE];
	char email[SIZE];
}sir[12], temp;

int main(void) {
	strcpy(list[0].number, "1");
	strcpy(list[1].number, "2");
	strcpy(list[2].number, "3");
	strcpy(list[3].number, "4");
	strcpy(list[4].number, "5");
	strcpy(list[5].number, "6");
	strcpy(list[6].number, "7");
	strcpy(list[7].number, "8");
	strcpy(list[8].number, "9");
	strcpy(list[9].number, "10");
	strcpy(list[10].number, "11");
	strcpy(list[11].number, "12");
	FILE *fp = fopen("prof_info2.txt", "r");
	FILE *txt_fp = fopen("sorted.txt", "w");

	if (txt_fp == NULL)
	{
		return 1;
	}

	if (fp == NULL)
	{
		return 1;
	}

	for (int i = 0; i < 12; i++)
	{
		fscanf(fp, "%s %s %s %s", sir[i].name, sir[i].office, sir[i].phone, sir[i].email);
	}
	fclose(fp);

	for (int i = 0; i < 12; i++) {
		for (int j = i; j < 12; j++) {
			if (strcmp(sir[i].office, sir[j].office) > 0) {
				temp = sir[i];
				sir[i] = sir[j];
				sir[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < 12; i++)
	{
		fputs(list[i].number, txt_fp);
		fputc('\t', txt_fp);
		fputs(sir[i].name, txt_fp);
		fputc('\t', txt_fp);
		fputs(sir[i].office, txt_fp);
		fputc('\t', txt_fp);
		fputs(sir[i].phone, txt_fp);
		fputc('\t', txt_fp);
		fputs(sir[i].email, txt_fp);
		fputc('\n', txt_fp);
	}

	return 0;
}