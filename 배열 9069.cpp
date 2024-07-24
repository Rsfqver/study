#include <stdio.h>

int main()
{
	int year; //년도 선언 
	int month;//달 선언 
	int i;  //정수 선언  
	int day[32];
	
	for(i=1; i<*day; i++)
	{
		if(i==2)
		{
			day[i]=28;
		}
		else if(i==4 || i==6 || i==9 || i==11)
		{
			day[i]=30;
		}
		else
		{
			day[i]=31;
		}
		
		
	}	
	while(1)
	{
		scanf("%d",&year);
        printf("YEAR = %d",year);
		
		scanf("%d",&month);
		printf("MONTH = %d",month);

		if(month==0)
		{
			break;
		}
		
		if(month<1 ||month>12)
		{
			printf("잘못 입력하였습니다");
			continue;
		}
		
		else if( i==2)
		{
				if(year%400==0||((year%4==0)&&(year%100!=0)))
			{
				day[2] = 29;
			}
				else
				{
					day[2] = 28;
				}
		}	

		printf("입력하신 달의 날수는 %d일입니다.\n",day[i]);
		
		}	
		

	return 0;
}
