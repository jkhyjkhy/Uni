#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define number 20

struct professor
{
	char name[number];
    char office[number];
    char phone[number];
	char email[number];
}sir[12];


int main(void)
{
	int i;
	FILE *fp = fopen("prof_info2.txt", "r");
	FILE *bin_fp = fopen("binary.dat", "wb");
	for (i = 0;i < 12;i++)
	{
		fscanf(fp, "%s %s %s %s", &sir[i].name, &sir[i].office, &sir[i].phone, &sir[i].email);
	}
	fclose(fp);

	for (i = 0;i < 12;i++)
	{
		fwrite(&sir[i], sizeof(sir[i]), 1, bin_fp);
	}
	for (i = 0;i < 12;i++)
	{
		printf("%s %s %s %s\n", sir[i].name, sir[i].office, sir[i].phone, sir[i].email);
	} //����ü�� ������ �� ���� ���� Ȯ�� �뵵�� ���� �ڵ��Դϴ�. �ǹ̾��� �ڵ忴���ϴ�.

	return 0;
}
	