#include <iostream>
using namespace std;

int main(){

	int a;
	int b;
	int *p;
	int *c;
	p=&a;
	c=&b;
	cin>>a;
	cin>>b;
	
	cout<<*p<<" + "<<*c<<' '<< "= "<<*p+*c;
}
