#include <iostream>
#include<string>
using namespace std;
/// <summary>
/// 2개의 생성자를 선언하는 클래스
/// </summary>
/// 
class Circle { //클래스함수
private:
	int radius;//길이 선언
public:
	Circle();//위임 생성자
	Circle(int r); //타겟 생성자 
	~Circle();
	double getArea() { return 3.14 * radius * radius; } //넓이 선언 
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};

Circle::Circle()  //위임 생성자 안에 타겟 생성자를 넣어 최적화를 구현 
 {
	radius = 1;
	cout << "\n생성자 실행 radius" << radius << "생성" << endl;
}


Circle::Circle(int radius)  //원의 넓이 식 구현
{
	this->radius = radius;
	cout << "\n생성자 실행 radius" << radius << "생성" << endl;
}

Circle::~Circle()  //위임 생성자 안에 타겟 생성자를 넣어 최적화를 구현 
{
	
	cout << "\n소멸자 실행 radius" << radius << "생성" << endl;
}

void increase(Circle c)
{
	int r = c.getRadius();
	c.setRadius(r + 1);

}

int main()
{
	Circle waffle(30);
	increase(waffle);
	cout << waffle.getRadius() << endl;
	/*char address[100];
	cin.getline(address, 100, '\n');

	cout << "주소는" << address << "입니다";
	*/
	return 0;

}