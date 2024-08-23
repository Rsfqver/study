#include<stdio.h>

int main()
{
	int num[10000]={1,1};
	int a=0;
	
	for(int i=2; i<40; i++)
	{
	
	num[i]=	num[i-1]+num[i-2];
	}
	
	for(int i=1; i<5; i++)
	{
		printf("파보나치 수열 %d항 : %d\n",i*10,num[i*10-1]);
	}
	return 0;
	
}
