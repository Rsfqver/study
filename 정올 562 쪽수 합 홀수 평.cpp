#include<iostream>
#include <stdlib.h>
using namespace std;


int main()
{
	
	int sum=10;
	int*p=(int*)malloc(sizeof(int)*sum); //동작 초기화  
	int add,avg,acg;
	cout<<fixed;
	cout.precision(2);
	
	for(int i=0; i<sum; i++)
	{
		cin>>p[i];
	}
		 //값이 짝수가 되야되는게 아니잖아 짝수 번째 값을 넣어야되는 조건이지 이 조건을 어떻게 해야할까? 
		 for(int i=1; i<sum; i+=2) //0부터 돌아가는게 원래 포문이니까? 
		{
			add+=p[i];
			 
		}
	for(int i=0; i<sum; i+=2) //0부터 돌아가는게 원래 포문이니까? 
		{
			
			 avg+=p[i];
			 acg=(double)avg/5;
		}
	
	cout<<"sum :"<<" "<<add<<endl;
	cout<<acg<<endl;
	//cout<<"avg :"<<" "<<avg/5<<endl;
	
}
