#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
	int a;
	cin>>a;
	int*p=(int*)malloc(sizeof(int)*a);
	int max,min=500; 
	
	for(int i=0; i<a; i++)
	{
		cin>>p[i]; //�Էºα��� ���� �Ϸ�  
		
		 if(min>p[i])
		 {
            min=p[i];
         }
         else if(max<p[i]) 
         {
         	max=p[i];
		 }
		 
		 
	}
	cout<<"max :"<<' '<<max<<"\n"<<"min :"<<' '<<min;

	
	return 0;
}
