#include<iostream>
using namespace std;


class CoffeeMachine
int coffe;
int suga;
int water;
	public:
		CoffeeMachine java(int a,int b,int c){coffe=a,b=suga,c=water;}
		drinkEspresso();
		drinkAmericnao();
		drinksugarcoffe();
		fill(){coffe=10,suga=10,water=10;}
		show();
		
void CoffeeMachine::show()
{
	cout<<"커피머신 상태,"<<' '<<"커피:"<<' '<<
	
}

void CoffeeMachine::drinkEspresso()
{
	coffe=coffe-1;
	water=water-1; 
}

void CoffeeMachine::drinkAmericnao()
{
	coffe=coffe-1;
	water=water-2; 
}

void drinksugarcoffe()
{
	coffe=coffe-1;
	water=water-2;
	suga=suga-1; 
	
}

/*
class Tower
{
	int h;
	public:
		Tower(){ h=1;}
		Tower(int a){ h=a;}
		int getHeight(){return h;}
};

int main()
{
	Tower myTower;
	Tower seoulTower(100);
	cout<< "높이는"<<myTower.getHeight()<< "미터"<<endl;
	cout<< "높이는"<<seoulTower.getHeight()<< "미터"<<endl;
 } */
 
 
/*
class Account
{
string name;
int id;
int balance;
	public:
		Account(string a,int b,int c){name=a,id=b,balance=c ;}
		string getOwner(){return name;}
		int deposit(int money){return balance=money+balance;}
		int withdraw(int money){return balance=balance-money;}
		int inquiry(){return balance;}
};*/
