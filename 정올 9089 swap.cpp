#include <iostream>
using namespace std;

void swap(int a, int b)
{
	int tmp;
	tmp=a;
	a=b;
	tmp=b;
}

void swap1(int *a, int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}



int main()
{
	int m,n;
	cout<<"두 수를 입력하세요.";
	cin>>m>>n;
	
	swap(m,n);
	cout<<"첫 번째 함수 실행중 x ="<<m<<", y ="<<n<<"\n";
	swap1(&m,&n);
	cout<<"첫 번째 함수 실행후 a ="<<m<<", b ="<<n<<"\n";
	
	swap1(&m,&n);
	cout<<"두 번째 함수 실행중 x ="<<m<<", y ="<<n<<"\n";
	swap(m,n);
	cout<<"두 번째 함수 실행후 a ="<<m<<", b ="<<n<<"\n";
	
	return 0; 
}

//초평 swap 함수 화룡해서 머리박치기 문제가 이상해서 알아처먹질못함  
