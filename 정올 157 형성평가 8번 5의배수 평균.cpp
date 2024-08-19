#include<stdio.h>


int main()
{
	int a[100];
	
	int sum,i,count;
	
	while(1)
	{
		scanf("%d",&a[i]);
		if(a[i]%5==0)
		{
			sum+=a[i];
			count++;
		}
		if(a[i]==0)
		{
		
		count--;
		break;
		}	
		i++;
	}
	
	printf("Multiples of 5 : %d \n",count);
	printf("sum : %d \n ",sum);
	printf("avg : %.1f",(float)sum/count);
	
}
