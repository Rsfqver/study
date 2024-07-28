#include <iostream>
using namespace std;

void line()
{
	int a,b,c;
	float avg;
	cout<<"세과목의 점수를 입력하세요.";
	cin>>a>>b>>c;
	avg=(float)(a+b+c)/3;
	
	
	
	cout<<fixed;
	cout.precision(2);
 	cout<<" 평균 :"<<' '<<avg;
}

int main (void)
{
	line();
	
	return 0;
 } 


//총평 그냥 입문 쉬운 문제  캐스팅 연산 잊지말것  


//총평 그냥 입문 쉬운 문제  소수점 표현을 알아야한다  
