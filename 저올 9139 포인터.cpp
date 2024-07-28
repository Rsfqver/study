#include <iostream>
using namespace std;

int main()
{
	
	int a;
	int b;
	int *p;
	int *c;
	p=&a;
	c=&b;
	cin>>a;
	cin>>b;
	cout<<"a = "<<a<<','<<' '<<"*p = "<<*p<<'\n';
	cout<<"a = "<<b<<','<<' '<<"*p = "<<*c<<'\n';
	cout<<"a = "<<a+10<<','<<' '<<"*p = "<<*p+10<<'\n';
	cout<<"a = "<<b+20<<','<<' '<<"*p = "<<*c+20<<'\n';
	cout<<"a = "<<a+24<<','<<' '<<"*p = "<<*p+24<<'\n';
	 
	
	return 0;
	
}

//총평 단순 노가다 
