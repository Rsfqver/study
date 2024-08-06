﻿#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class HangMan
{
    ifstream fin; // 파일 열기 위한 변수 지정 
    vector<string> v;
    char tmp[2];
    int tmpNum[2];
public:
    HangMan();
    void fileRead(vector<string>& v, ifstream& fin); // 파일 읽는 구성부 
    string maketext(); // 텍스트 생성 // 문제 구성부 
    string Answer(string text); // 문제 답변 
    void run(); // 실행파일 exe
    ~HangMan(); // 소멸자 
};

HangMan::HangMan()
{
    const char* file = "words.txt";
    fin.open(file);
    if (!fin)
    {
        cout << file << " 파일 열기에 실패" << endl;
        exit(1);
    }
}

void HangMan::fileRead(vector<string>& v, ifstream& fin)
{
    string line;
    while (getline(fin, line))
        v.push_back(line);
}

string HangMan::maketext()
{
    srand((unsigned)time(NULL));
    int n = rand() % v.size();
    string text = v.at(n);

    int i = 0;
    while (i < 2)
    {
        int num = rand() % text.size();
        bool duplicate = false;
        for (int j = 0; j < i; j++)
        {
            if (tmpNum[j] == num)
            {
                duplicate = true;
                break;
            }
        }
        if (!duplicate)
        {
            tmpNum[i] = num;
            tmp[i] = text[num];
            text[num] = '-';
            i++;
        }
    }
    return text;
}

string HangMan::Answer(string text) // 게임 답변
{
    int scount = 0;
    int fcount = 0;
    char user;

    while (true)
    {
        cout << ">>";
        cin >> user;

        bool found = false;
        for (int i = 0; i < 2; i++)
        {
            if (user == tmp[i])
            {
                scount++;
                text[tmpNum[i]] = user;
                cout << text << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            fcount++;
        }

        if (fcount == 5)
        {
            cout << "5번 실패 다시 시작합니다" << endl;
            text[tmpNum[0]] = tmp[0];
            text[tmpNum[1]] = tmp[1];
            return text;
        }
        if (scount == 2)
        {
            string s = "정답";
            return s;
        }
    }
}

HangMan::~HangMan()
{
    if (fin.is_open())
        fin.close();
}

void HangMan::run()
{
    cout << "---------------------" << endl;
    cout << "게임을 시작합니다" << endl;
    cout << "---------------------" << endl;
    fileRead(v, fin);
    while (true)
    {
        string text = maketext();
        char go;
        cout << text << endl;
        cout << Answer(text) << endl;

        while (true)
        {
            cout << "Next(y/n)?" << endl;
            cin >> go;
            if (go == 'y') break;
            else if (go == 'n') exit(1);
            else
            {
                cout << "잘못 입력" << endl;
                continue;
            }
        }
    }
}

int main()
{
    HangMan a;
    a.run();
}
