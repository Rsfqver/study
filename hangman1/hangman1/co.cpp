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
    ifstream fin; // ���� ���� ���� ���� ���� 
    vector<string> v;
    vector<char> tmp;  // ���̰� �� ����
    vector<int> tmpNum; // ���̰� �� ������ �ε���
public:
    HangMan();
    void fileRead(); // ���� �д� ������ 
    string maketext(); // �ؽ�Ʈ ���� // ���� ������ 
    string Answer(string text); // ���� �亯 
    void run(); // �������� exe
    ~HangMan(); // �Ҹ��� 
};

HangMan::HangMan()
{
    const char* file = "words.txt";
    fin.open("words.txt");
    if (!fin) // ���� ���� ���� ���� ����
    {
        cout << file << " ���� ���⿡ ����" << endl;
        exit(1);
    }
}

void HangMan::fileRead()
{
    string line;
    while (getline(fin, line))
    {
        if (!line.empty()) // �� �� ����
            v.push_back(line);
    }
}

string HangMan::maketext()
{
    srand((unsigned)time(NULL)); // �õ� �ʱ�ȭ
    int n = rand() % v.size(); // ���� ũ��� ����
    string text = v.at(n);

    // ���� ���� 2�� �̻����� Ȯ��
    if (text.size() < 2)
    {
        cout << "�ܾ �ʹ� ª���ϴ�." << endl;
        exit(1);
    }

    // 2���� ���� �ε����� ���� (�ߺ� ���)
    set<char> uniqueChars; // �ߺ� ������ ���� set
    while (uniqueChars.size() < 2)
    {
        int index = rand() % text.size();
        uniqueChars.insert(text[index]); // �ߺ��� ���ڴ� �ڵ����� ���õ�
    }

    // ���̴� ������ �ε����� ���ڸ� ����
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

    // ���� �ؽ�Ʈ���� ���̴� ���ڸ� '-'�� ����
    for (size_t j = 0; j < text.size(); j++)
    {
        if (find(tmpNum.begin(), tmpNum.end(), j) == tmpNum.end()) // ���̴� ���ڰ� �ƴϸ� '-'�� ����
            text[j] = '-';
    }

    // ������ ���ڵ鸸 �����ݴϴ�.
    for (size_t i = 0; i < tmpNum.size(); i++)
    {
        text[tmpNum[i]] = tmp[i]; // tmp���� �� ���ڸ� ������ ���� ��ġ�� ����
    }

    return text;
}

string HangMan::Answer(string text) // ���� �亯
{
    int scount = 0; // ���� ����
    int fcount = 0; // Ʋ�� ����
    char user;

    while (true)
    {
        cout << ">> ";
        cin >> user;

        bool found = false; // ���ڰ� �߰ߵǾ����� ����
        for (size_t i = 0; i < tmp.size(); i++)
        {
            if (user == tmp[i])
            {
                found = true;
                // ��� �ε����� ���� ���ڸ� ������� ����
                for (size_t j = 0; j < tmpNum.size(); j++)
                {
                    if (text[tmpNum[j]] == tmp[i]) {
                        text[tmpNum[j]] = user; // ���� ���ڷ� ����
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
            cout << "Ʋ�Ƚ��ϴ�. ���� ��ȸ: " << 5 - fcount << endl;
        }

        if (fcount == 5)
        {
            cout << "5�� ���з� ������ ����˴ϴ�." << endl;
            return text;
        }
        if (scount == tmp.size())
        {
            return "����";
        }
    }
}

HangMan::~HangMan()
{
    fin.close(); // �Ҹ��ڿ��� ���� �ݱ�
}

void HangMan::run()
{
    cout << "---------------------" << endl;
    cout << "������ �����մϴ�" << endl;
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
                cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ���." << endl;
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