#include <stdio.h>

int main()
{
	int num[100],i,count;
	for(i=0; i<100; i++)
	{
		scanf("%d",&num[i]);
		if(num[i]==0)
		{
			break;
		}
	}
	count=i;
	for(i=1; i<count; i+=2)
	{
		printf(" %d",num[i]);
	}
	return 0;
}
