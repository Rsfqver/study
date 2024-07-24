#include <stdio.h>

int main()
{
    int num=0;
    
    
	while(1)
	{
		printf("number? ");
		scanf("%d",&num);
		
		if(num>0)
		{
		
		printf("npositive integer\n");	 
		}
		else if (num<0)
    	{
    	
    	printf("negative numbe \n");
    	}
    	else
        break;
	}
   
return 0;
}
