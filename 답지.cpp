#include <stdio.h>

int main()
{
	int num = 0;
	int count = 0;
	int sum = 0;
	float avg = 0;

	// printf("������ �Է��ϼ���. ");
	scanf("%d", &num);

	while (1)
	{
		if (num == 0)
		{
			printf("�Էµ� �ڷ��� ���� = %d\n", count);
			printf("�Էµ� �ڷ��� �հ� = %d\n", sum);
			printf("�Էµ� �ڷ��� ��� = %.2f\n", avg);
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
