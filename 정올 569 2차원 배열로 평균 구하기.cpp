#include <stdio.h>

int main()
{
	int score[5][4]={0,};
	int i,j,count,sum;
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<4; j++)
		{
			scanf("%d",&score[i][j]);
		}
	}
	
	for(i=0; i<5; i++)
	{
		for(j=0; j<4; j++)
		{
			sum+=score[i][j];
		}
		if((sum/4)>=80)
		{
			printf("pass\n");
			count++;
		}
		else
		{
			printf("fail\n");
		}
		sum =0; //µ°º¿ ±∏∞£¿ª √ ±‚»≠  
	}
	
	
	 printf("Successful : %d ",count);

	return 0;
}


