#include<stdio.h>
#include<stdlib.h>

int search(const int a[], int n,int key)
{
	int i=0;
	a[n]=key; //보초법 적용 
	for(i=0; i<n; i++)
	{
		if(a[i]==key)
		return i;
		else
		return-1;//retunr을 사용해 무한 루프 탈출   
	}
}

int main()
{
	int nx,ky;
	puts("선형 검색");
	printf("요소 갯수 :");
	scanf("%d",&nx);
	int *x=(int *)calloc(nx, sizeof(int));
	
	for(int i=0; i<nx; i++)
	{
		printf("x[%d]:",i);
		scanf("%d",&x[i]);
	}
	printf("검색값 :");
	scanf("%d", &ky);
	
	int idx=search(x,nx,ky);
	if(idx==-1)
		puts("검색에 실패");
	else
	printf("%d는 x[%d]에 있다\n",ky,idx);
	free(x);
	
	return 0;
}
