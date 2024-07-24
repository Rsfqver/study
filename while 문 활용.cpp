#include <stdio.h>
int main()
{
int a=0;//자료 입력 받을것
int title=0;
int sum=0;
float ave=0;

scanf("%d",&a);

while(1)
{
    if(a==0)
	{
		printf("입력된 자료의 개수 = %d\n", title);
		printf("입력된 자료의 합계 =%d\n", sum);
		printf("입력된 자료의 평균 =%.2f\n", ave);
		return 0;
	}

    else
		{
    	title++;
   		sum+=a;
    	ave=sum;
    	ave/=title;
		 }
 scanf("%d",&a);

}
return 0;
}
