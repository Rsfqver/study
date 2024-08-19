#include<stdio.h>
int main()
{
		int a[100];
	
	int sum,i,count;
	while(1)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)
		{
		break;
		
		}	
		i++;
		}
	printf("%d \n",i);
	for(int j=0; j<i; j++)
	{
		if(a[j] % 2 ==0)
		printf("%d ",a[j]/2);
		else
		printf("%d ",a[j]*2);
	}
	
}
