#include<stdio.h>

int main()
{
	int num[10]={0,};
	int a=0;
	
	while(1)
	{
		scanf("%d",&a);
		if(a==0)
		{
			break;
		}
		
			num[(a / 10)]++;
	}
			for(int i=0; i<10; i++)
			{
				if(num[i]!=0)
				{
				
					printf("%d: %d°³ \n",i,num[i]);
				}
			}
		
	
	
	return 0;
	
}
