#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)


{

	int score[5];
	int sum = 0;
	int avg = 0;

	srand(time(NULL));

	printf("����\n");

	for (int i = 0; i < 5;i++)
	{
		score[i] = rand() % 41 + 60;

		sum += score[i];

		printf("%d ", score[i]);
	}
	avg = sum / 5;

	if (avg >= 90)
		printf("\n������� : %d , ���� : A\n", avg);
	else if (avg >= 80)
		printf("\n������� : %d , ���� : B\n", avg);
	else if (avg >= 70)
		printf("\n������� : %d , ���� : C\n", avg);
	else if (avg >= 60)
		printf("\n������� : %d , ���� : D\n", avg);
	else
		printf("\n������� : %d , ���� : F\n", avg);

	return 0;
}

