#include <iostream>
#include<string>

using namespace std;

int main ()
{
	int num[100];
	int max; //�ִ밪�� ������ �Լ�
	int i;
	int min;
	for(i=0; i<10; i++)
	{
		cin >> num[i];
	}
	 min=num[0];
	 max=num[0];
	for(i=0; i<10; i++)
	{
		
			if(num[i]%2==0){
			
			{
			if(max <num[i])
			max = num[i];
			}
		}
		
		else
		{
			if(min>num[i])
		{
			min=num[i];
		}
		}
		
	}
	cout<<min<<' '<<max<<endl;
	
	return 0 ;
}
// ���� :eles�� ��ǥ�뱳�� ����Գ�? 
