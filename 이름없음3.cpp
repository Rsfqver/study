#include <iostream>
using namespace std;


int factorial(int n)
{  
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}


int main()
{
   int n;
   cout<<"수를 입력 하세요 ";
   cin>>n ;
   
   cout<<factorial(n)<<endl;
   
    return 0;
}









