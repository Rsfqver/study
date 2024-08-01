#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
	int a;
	int*p=(int*)malloc(sizeof(int)*a);
	int count=0,acount=0;

	for(int i=0; i<10; i++)
	{
		cin>>p[i];
		
		if(p[i]%2==1)//È¦¼ö  
		{
			count++;
		}
		else //Â¦¼ö  
		{
		acount++;
		}
	}
	
	cout<<"odd :"<<' '<<count<<endl;
	cout<<"even :"<<' '<<acount;
	
	return 0;
}
