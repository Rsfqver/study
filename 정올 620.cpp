#include <iostream>
using namespace std;

int main()
{
	
	int a;
	int *p;
	cin>>a;
	p=&a;
	
	cout<<*p/10<<"..."<<*p%10;
}
