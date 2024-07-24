#include <stdio.h>


int main(void)
{

	int a[]={10,1,2,3,4,5,6,7,8,9};
	int *p;
	p=a;
	
	printf("%d\n", *p++);  //10
	printf("%d\n", *(p++));//1 /1008
	printf("%d\n", (*p)++);//3 (*p)=(*p)+1
	printf("%d\n", ++*p);//4
	printf("%d\n", *++p);//3
	 
return 0;
}


 
