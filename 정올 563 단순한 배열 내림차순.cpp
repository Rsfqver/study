#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
	int count[10]={95,100,88,65,76,89,58,93,77,99};

	int i,j,temp; 
	
	for(i=0; i<10; i++)
	{
		for(j=0; j<10; j++)
		{
			if(count[i]>count[j])
			{
				temp=count[i];
			count[i]=count[j];
			count[j]=temp;
			}
		}
	}
	
	for(i=0;i<10; i++) 
	cout<<count[i]<<' ';
	return 0;
	
 } 
