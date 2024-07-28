#include <iostream>
using namespace std;


void line()
{
	int n;
	cin>>n;
	 int j;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{
			cout<<"*";
		}
		cout<<"\n";
	}
	
}

int main (void)
{
	line();
	
	return 0;
 } 


//총평 그냥 입문 쉬운 문제  for문 활용을 잘할것 삼각형을 작성할때 밑으로 n을 보내주어야함  
