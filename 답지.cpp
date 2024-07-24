#include <stdio.h>

int main()
{
	int num = 0;
	int count = 0;
	int sum = 0;
	float avg = 0;

	// printf("점수를 입력하세요. ");
	scanf("%d", &num);

	while (1)
	{
		if (num == 0)
		{
			printf("입력된 자료의 개수 = %d\n", count);
			printf("입력된 자료의 합계 = %d\n", sum);
			printf("입력된 자료의 평균 = %.2f\n", avg);
			return 0;
		}
		else
		{
			count++;
			sum += num;
			avg = sum;
			avg /= count;
		}

		scanf("%d", &num);
	}

	return 0;
}
