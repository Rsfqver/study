#include <stdio.h>

int main()
{
	int year; //�⵵ ���� 
	int month;//�� ���� 
	int i;  //���� ����  
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
			printf("�߸� �Է��Ͽ����ϴ�");
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

		printf("�Է��Ͻ� ���� ������ %d���Դϴ�.\n",day[i]);
		
		}	
		

	return 0;
}
