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


//���� �׳� �Թ� ���� ����  for�� Ȱ���� ���Ұ� �ﰢ���� �ۼ��Ҷ� ������ n�� �����־����  
