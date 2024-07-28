#include <iostream>
using namespace std;

void line()
{
	int m=1; //루프로 돌아는 숫자를 표현해줄 통로 구현  
	int n;
	cin>>n;
	 int j;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
        
		cout<<m++<<' ';
		}
		cout<<'\n';
	}
	
}

int main (void)
{
	line();
	
	return 0;
 } 


//총평 2중 포문을 작성하고 이 루프를 출력하는 변수까지 같이 구현해야한다  
