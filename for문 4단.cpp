#include <stdio.h>

int main()
{
	
	
	int a=0;
	scanf("%d",&a);
	int sum=0; 
	
	for(int i=0; i<=a; i++)
	{
		if(i%5==0){
	sum+=i;	
	}
	
	}
	printf("%d ",sum);
		return 0;	
}
