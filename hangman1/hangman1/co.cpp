/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <set>

using namespace std;

class HangMan
{
    ifstream fin; // 파일 열기 위한 변수 지정 
    vector<string> v;
    vector<char> tmp;  // 보이게 할 글자
    vector<int> tmpNum; // 보이게 할 글자의 인덱스
public:
    HangMan();
    void fileRead(); // 파일 읽는 구성부 
    string maketext(); // 텍스트 생성 // 문제 구성부 
    string Answer(string text); // 문제 답변 
    void run(); // 실행파일 exe
    ~HangMan(); // 소멸자 
};

HangMan::HangMan()
{
    const char* file = "words.txt";
    fin.open("words.txt");
    if (!fin) // 파일 열기 실패 조건 수정
    {
        cout << file << " 파일 열기에 실패" << endl;
        exit(1);
    }
}

void HangMan::fileRead()
{
    string line;
    while (getline(fin, line))
    {
        if (!line.empty()) // 빈 줄 무시
            v.push_back(line);
    }
}

string HangMan::maketext()
{
    srand((unsigned)time(NULL)); // 시드 초기화
    int n = rand() % v.size(); // 벡터 크기로 수정
    string text = v.at(n);

    // 글자 수가 2개 이상인지 확인
    if (text.size() < 2)
    {
        cout << "단어가 너무 짧습니다." << endl;
        exit(1);
    }

    // 2개의 랜덤 인덱스를 선택 (중복 허용)
    set<char> uniqueChars; // 중복 방지를 위한 set
    while (uniqueChars.size() < 2)
    {
        int index = rand() % text.size();
        uniqueChars.insert(text[index]); // 중복된 글자는 자동으로 무시됨
    }

    // 보이는 글자의 인덱스와 글자를 저장
    tmp.clear();
    tmpNum.clear();
    for (char c : uniqueChars) {
        for (size_t j = 0; j < text.size(); j++) {
            if (text[j] == c) {
                tmp.push_back(c);
                tmpNum.push_back(j);
            }
        }
    }

    // 원본 텍스트에서 보이는 글자를 '-'로 변경
    for (size_t j = 0; j < text.size(); j++)
    {
        if (find(tmpNum.begin(), tmpNum.end(), j) == tmpNum.end()) // 보이는 글자가 아니면 '-'로 변경
            text[j] = '-';
    }

    // 선택한 글자들만 보여줍니다.
    for (size_t i = 0; i < tmpNum.size(); i++)
    {
        text[tmpNum[i]] = tmp[i]; // tmp에서 각 글자를 가져와 원래 위치에 대입
    }

    return text;
}

string HangMan::Answer(string text) // 게임 답변
{
    int scount = 0; // 맞춘 개수
    int fcount = 0; // 틀린 개수
    char user;

    while (true)
    {
        cout << ">> ";
        cin >> user;

        bool found = false; // 글자가 발견되었는지 여부
        for (size_t i = 0; i < tmp.size(); i++)
        {
            if (user == tmp[i])
            {
                found = true;
                // 모든 인덱스에 대해 글자를 원래대로 복원
                for (size_t j = 0; j < tmpNum.size(); j++)
                {
                    if (text[tmpNum[j]] == tmp[i]) {
                        text[tmpNum[j]] = user; // 원래 글자로 복원
                    }
                }
                cout << text << endl;
                scount++;
                break;
            }
        }

        if (!found)
        {
            fcount++;
            cout << "틀렸습니다. 남은 기회: " << 5 - fcount << endl;
        }

        if (fcount == 5)
        {
            cout << "5번 실패로 게임이 종료됩니다." << endl;
            return text;
        }
        if (scount == tmp.size())
        {
            return "정답";
        }
    }
}

HangMan::~HangMan()
{
    fin.close(); // 소멸자에서 파일 닫기
}

void HangMan::run()
{
    cout << "---------------------" << endl;
    cout << "게임을 시작합니다" << endl;
    cout << "---------------------" << endl;
    fileRead();
    while (true)
    {
        string text = maketext();
        char go;
        cout << text << endl;
        cout << Answer(text) << endl;

        while (true)
        {
            cout << "Next(y/n)? ";
            cin >> go;
            if (go == 'y') break;
            else if (go == 'n') exit(0);
            else
            {
                cout << "잘못 입력하셨습니다. 다시 입력하세요." << endl;
            }
        }
    }
}

int main()
{
    HangMan a;
    a.run();
}
*/