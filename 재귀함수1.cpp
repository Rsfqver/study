#include <stdio.h>
 int sum[10];
 int a = 0;
 
void dice(int N, int M)
{
	int i=0;
    for (i = 1; i <= 6; ++i)
    {
       sum[a] = i;
       if (a == N - 1)
        {
            int total = 0;
            for (int j = 0; j <= a; ++j)
                total += sum[j];
 
            if (total == M)
            {
                for (int k = 0; k < N; ++k)
                    printf("%d ", sum[k]);
                printf("\n");
                return;
            }
        }
        else
        {
            a++;
            dice(N, M);
            a--;
        }
    }
}
 
int main()
{
    int i, j;
    scanf("%d %d", &i,&j);
 
    dice(i, j);
 
    return 0;
}
		

  
