#include <iostream>
using namespace std;

void line()
{
	int m=1; //������ ���ƴ� ���ڸ� ǥ������ ��� ����  
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


//���� 2�� ������ �ۼ��ϰ� �� ������ ����ϴ� �������� ���� �����ؾ��Ѵ�  
