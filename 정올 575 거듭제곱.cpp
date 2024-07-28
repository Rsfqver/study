#include <iostream>
#include <math.h> 
using namespace std;

int math(int a, int b)
{
	return pow(a,b);
	
}

int main (void)
{
 	int a,b,c;
 	cin>>a>>b;
	cout<<math(a,b);
	return 0;
 } 
 
 //총평 math함수를 활용하면 쉽게 구현이 가능하다  
