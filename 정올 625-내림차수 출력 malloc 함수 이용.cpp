#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
	int count;
	cin>>count;
	int*p=(int*)malloc(sizeof(int)*count);
	int i,j,temp; 
	
	for(i=0; i<count; i++)
	{
		 cin>>p[i]; 
	}
	
	for(i=0; i<count; i++)
	{
		for(j=0; j<count; j++)
		{
			if(p[i]>p[j])
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	
	for(i=0;i<count; i++) 
	cout<<p[i]<<' ';
	return 0;
	
 } 
