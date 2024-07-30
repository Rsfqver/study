// 6 up and down game.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

class Person
{
    string name;
public:
    void setname(string n) { name = n; }
    string getname() { return name; }
    //닉네임 클래스 생성 
};

class Updonwgame
{
   static int n;//숫자 받을 정수 선언
   static int k, l;//k와l사이에 있습니다~
public:
    static void game();
};

int Updonwgame::n; // 정답은 0부터 99 사이의 랜덤한 숫자
int Updonwgame ::k = 0;
int Updonwgame ::l = 99;
void Updonwgame::game()
{
    Updonwgame::n = rand() % 100;
    cout << "Up & Down 게임을 시작합니다" << endl;
    Person p[2];
    p[0].setname("김인수>>");
    p[1].setname("오은경>>");

    int i = 0;
    bool sw;
    for (;;)
    {
        sw = true;
        cout << "답은" << k <<"또는" << l << "사이에 있습니다"<<'\n';
        cout << p[i%2].getname(); //번갈아 순서 
        int num;
        cin >> num;
        if (num < Updonwgame::n)
        {// 입력 받은 숫자가 답보다 낮으면 num과 right 사이이므로
            Updonwgame::k = num;
        }// left 를 num으로 변경
        else if (num > Updonwgame::n)
        {// 입력 받은 숫자가 답보다 높으면 left와 num 사이이므로
            Updonwgame::l = num;
        }// right를 num 으로 변경
        else if (num == Updonwgame::n)
        { // 답과 같다면
            cout << p[i % 2].getname() << "가 이겼습니다!!" << endl; // 해당 플레이어 승리
            break;
        }
        else 
        {
            cout << "입력이 잘못 되었습니다.다시 입력하세요" << endl;
            sw = false;
        }
        if (sw) ++i;
    }
}

int main()
{
    srand((unsigned)time(0));
    Updonwgame::game();

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
