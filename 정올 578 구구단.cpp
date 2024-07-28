#include <iostream>
using namespace std;

void gugu(int a, int b)
{
	int i,j;
	if(a>b)
	{
		i=a;
		a=b;
		b=i;
	}
	
	for(i=a; i<=b; i++)
	{
		cout<<"== "<<i<<"dan =="<<" \n";
		for(j=1; j<=9; j++)
		{
		cout<<i<<" * "<<j<<"="<<" "<<i*j<<"\n";
		}
		
		cout<<"\n";
	}
}

int main()
{
	int a;
	int b;
	cin>>a>>b;
	
	gugu(a,b);
}

//띄어쓰기 개 조트  
