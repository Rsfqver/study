#include<iostream>
#include <stdlib.h>
using namespace std;


int main()
{
	
	int sum=10;
	int*p=(int*)malloc(sizeof(int)*sum); //���� �ʱ�ȭ  
	int add;
	cout<<fixed;
	cout.precision(1);
	
	for(int i=0; i<sum; i++)
	{
		cin>>p[i];
		add+=p[i];
		
	}
	
	cout<<"����"<<' '<<"="<<add<<endl;

	cout<<"���"<<' '<<"="<<add/(double)sum<<endl;
	
	return 0;
	} 
