#include<iostream>
#include <stdlib.h>
using namespace std;


int main()
{
	
	int sum=10;
	int*p=(int*)malloc(sizeof(int)*sum); //���� �ʱ�ȭ  
	int add,avg,acg;
	cout<<fixed;
	cout.precision(2);
	
	for(int i=0; i<sum; i++)
	{
		cin>>p[i];
	}
		 //���� ¦���� �ǾߵǴ°� �ƴ��ݾ� ¦�� ��° ���� �־�ߵǴ� �������� �� ������ ��� �ؾ��ұ�? 
		 for(int i=1; i<sum; i+=2) //0���� ���ư��°� ���� �����̴ϱ�? 
		{
			add+=p[i];
			 
		}
	for(int i=0; i<sum; i+=2) //0���� ���ư��°� ���� �����̴ϱ�? 
		{
			
			 avg+=p[i];
			 acg=(double)avg/5;
		}
	
	cout<<"sum :"<<" "<<add<<endl;
	cout<<acg<<endl;
	//cout<<"avg :"<<" "<<avg/5<<endl;
	
}
