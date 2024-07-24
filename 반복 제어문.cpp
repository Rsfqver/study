#include<stdio.h>

int main (void)
{
int num=0;
int cout=0;
int sum=0;


while(1)
{
scanf("%d",&num);	
if(num<0||num>100)
{
 break;
}
else
{
		cout++;
		sum+=num;
		
}
}
	printf("sum : %d\n",sum);
    printf("avg : %.1f\n",(float)sum/cout);
return 0;
}
