#include <stdio.h>

int main (void){
	
	char X;
	 scanf("%c",&X);

	 if(X=='A')
	 {
	  printf("Excellent");
	}	
    
	 else if(X=='B')
	 {
	  printf("Good");
	}	
    
	else if(X=='C')
	{
	  printf("Usually");
	}	
    
	else if(X=='D')
	{
	  printf("Effort");
	}
	else if(X=='F')
	{
	  printf("Failure");
	}
	
	else{
		printf("error");
	}	
 
     return 0;
}
