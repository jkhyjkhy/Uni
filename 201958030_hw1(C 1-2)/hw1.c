#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)


{

	int score[5];
	int sum = 0;
	int avg = 0;

	srand(time(NULL));

	printf("점수\n");

	for (int i = 0; i < 5;i++)
	{
		score[i] = rand() % 41 + 60;

		sum += score[i];

		printf("%d ", score[i]);
	}
	avg = sum / 5;

	if (avg >= 90)
		printf("\n평균점수 : %d , 성적 : A\n", avg);
	else if (avg >= 80)
		printf("\n평균점수 : %d , 성적 : B\n", avg);
	else if (avg >= 70)
		printf("\n평균점수 : %d , 성적 : C\n", avg);
	else if (avg >= 60)
		printf("\n평균점수 : %d , 성적 : D\n", avg);
	else
		printf("\n평균점수 : %d , 성적 : F\n", avg);

	return 0;
}

