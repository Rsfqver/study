#include<stdio.h>

int main (void)
{
int a,b=0;

char c;

while(1)
{
	if(c=='y'||c=='Y'){
	
	printf("Base =\n");
	scanf("%d",&a);
	printf("Height =\n");
	scanf("%d",&b);
	printf("Triangle width = %d\n",((float)a*b)/2);
	
	printf("Continue?");
	scanf("%c",&c);
	
	
}
  else
  {
		break;
	} 
}



return 0;
}




