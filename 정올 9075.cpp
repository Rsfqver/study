#include<stdio.h>

int main()
{
	int num[11]={0,};
	int a=0;
	
	while(1)
	{
		scanf("%d",&a);
		if(a==0)
		{
			for(int i=0; i<10; i++)
			{
				if(num[i]!=0)
				{
					printf("%d: %d°³ \n",i,num[i]);
				}
				else
				{
					continue;
				}
			}
		break;	
		}
		else
		{
			num[a%10]++;
		}
	}
	
	return 0;
	
}
