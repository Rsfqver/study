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
	cout<<"�� ���� �Է��ϼ���.";
	cin>>m>>n;
	
	swap(m,n);
	cout<<"ù ��° �Լ� ������ x ="<<m<<", y ="<<n<<"\n";
	swap1(&m,&n);
	cout<<"ù ��° �Լ� ������ a ="<<m<<", b ="<<n<<"\n";
	
	swap1(&m,&n);
	cout<<"�� ��° �Լ� ������ x ="<<m<<", y ="<<n<<"\n";
	swap(m,n);
	cout<<"�� ��° �Լ� ������ a ="<<m<<", b ="<<n<<"\n";
	
	return 0; 
}

//���� swap �Լ� ȭ���ؼ� �Ӹ���ġ�� ������ �̻��ؼ� �˾�ó��������  
