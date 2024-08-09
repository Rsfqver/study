#include<stdio.h>
#include<stdlib.h>
int int_cmp(const int *a, const int*b)
{
	if(*a<*b)
	return -1;
	else if(*a > *b)
	return 1;
	else
	return 0;
}

int main()
{
	int nx,ky;
	puts("함수를 입력");
	printf("요소 개수");
	scanf("%d",&nx);
	int *x=(int*)calloc(nx,sizeof(int));
	
	printf("오름차순으로 입력\n");
	printf("x[0]:");
	scanf("%d",&x[0]);
	for(int i=1; i<nx; i++)
	{
		do
		{
			printf("x[%d]:",i);
			scanf("%d",&x[i]);
		}while(x[i]>x[i-1]);
	}
	printf("검색 값:");
	scanf("%d",&ky);
	int *p = (int *)bsearch(&ky, x, nx, sizeof(int), (int (*)(const void*, const void*))int_cmp);

	
	if(p==NULL)
		{puts("검색에 실패했습니다");}
		else
		printf("%d는 x[%d]에 있다 \n",ky,(int)(p-x));
		free(x);
		return 0; 
}
