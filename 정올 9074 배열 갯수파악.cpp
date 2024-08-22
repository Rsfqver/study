#include <stdio.h>

int main()
{
	int a[11]={0,};
	int num;
	
	
	while(1)
	{
		scanf("%d",&num);
		if(num>0&& num<11)
			{
			a[num-1]++;
		}
		
		else
		{
			for(int i=0; i<10; i++)
			{
				if(a[i]==0)
				{
				
				continue;
			}
			
			else
			{
				printf("%d : %d°³\n",i+1, a[i]);
			}
			}
		break;
		}
	}
	
	return 0;
}
