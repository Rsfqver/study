#include <vector> //가변 크기의 배열을 일반화
#include <algorithm>//stl의 다양한 기능을 선언하는 알고리즘  헤더
#include <fstream>
#include <sstream>//문자열 정리 헤더 
#include <iomanip> //입출력 조정 헤더
//문자단위 입력 스트림 istram,ostram 문자단위 출력 iostram 문자단위 입출력을 동시에 시행한다
//ifstream 파일 읽기 ofstream 파일쓰기 fstream읽고 쓰기 동시에 
#include "client.h"
#include "clientmanager.h"

ClientManager::ClientManager() //파일  읽기 클래스의 생성자 상세 구현 
{
   ifstream file;
   file.open("clientlist.txt");
   if(!file.fail()) {
       while(!file.eof()) {
           vector<string> row = parseCSV(file, ',');
           if(row.size()) {
               int id = atoi(row[0].c_str());
               Client* c = new Client(id, row[1], row[2], row[3]);
               clientList.insert( { id, c } );
           }
       }
   }
   file.close( );
}

ClientManager::~ClientManager() //문자 출력 클래스

{
   ofstream file; 
   file.open("clientlist.txt");
   if(!file.fail()) {
      for (const auto& v : clientList) {
          Client* c = v.second;
          file << c->id() << ", " << c->getName() << ", ";
          file << c->getPhoneNumber() << ", ";
          file << c->getAddress() << endl;
      }
   }
   file.close( );
}

void ClientManager::inputClient( ) //고객 정보 아이디 생성자의 상세 구현 
{
    string name, number, address;
    cout << "name : "; cin >> name;
    cout << "number : "; cin >> number;
    cout << "address : "; cin.ignore(); getline(cin, address, '\n'); //cin >> address;

    int id = makeId( );
    Client* c = new Client(id, name, number, address);
    clientList.insert( { id, c } );
}

Client* ClientManager::search(int id) //고객 아이디 서치 생성자 구현 
{
    return clientList[id];
}

void ClientManager::deleteClient(int key) //고객 정보 삭제 
{
    clientList.erase(key);
}

void ClientManager::modifyClient(int key) //고객 정보 수정 
{
    Client* c = search(key);
    cout << "  ID  |     Name     | Phone Number |       Address" << endl;
    cout << setw(5) << setfill('0') << right << c->id() << " | " << left;
    cout << setw(12) << setfill(' ') << c->getName() << " | ";
    cout << setw(12) << c->getPhoneNumber() << " | ";
    cout << c->getAddress() << endl;

    string name, number, address;
    cout << "name : "; cin >> name;
    cout << "number : "; cin >> number;
    cout << "address : "; cin.ignore(); getline(cin, address, '\n'); //cin >> address;

    c->setName(name);
    c->setPhoneNumber(number);
    c->setAddress(address);
    clientList[key] = c;
}

void ClientManager::displayInfo() //디스플레이 정보 구현 
{
    cout << endl << "  ID  |     Name     | Phone Number |       Address" << endl;
    for (const auto& v : clientList) {
         Client* c = v.second;
         cout << setw(5) << setfill('0') << right << c->id() << " | " << left;
         cout << setw(12) << setfill(' ') << c->getName() << " | ";
         cout << setw(12) << c->getPhoneNumber() << " | ";
         cout << c->getAddress() << endl;
    }
}

void ClientManager::addClient(Client* c)//고객의 정보를 리스트에 삽입하는 생성자  구현
{
    clientList.insert( { c->id(), c } );
}

int ClientManager::makeId( ) //아이디 생성 
{
    if(clientList.size( ) == 0) {
        return 0;
    } else {
        auto elem = clientList.end();
        int id = (--elem)->first;
        return ++id;
    }
}

vector<string> ClientManager::parseCSV(istream &file, char delimiter) //파일 읽고 분석하는 생성자 구현?
{
    stringstream ss;
    vector<string> row;
    string t = " \n\r\t";

    while(!file.eof()) {
        char c = file.get();
        if (c==delimiter || c=='\r' || c=='\n') {
            if(file.peek()=='\n') file.get();
            string s = ss.str();
            s.erase(0, s.find_first_not_of(t));
            s.erase(s.find_last_not_of(t)+1);
            row.push_back(s);
            ss.str("");
            if (c!=delimiter) break;
        } else {
            ss << c;
        }
    }
    return row;
}


bool ClientManager::displayMenu()  //디스플레이 메뉴 구현 
{
    int ch, key;
    cout << "\033[2J\033[1;1H";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "              Client Manager                 " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "  1. Display Client List                     " << endl;
    cout << "  2. input Client                            " << endl;
    cout << "  3. Delete Client                           " << endl;
    cout << "  4. Modify Client                           " << endl;
    cout << "  5. Quit this Program                       " << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << " What do you wanna do? ";
    cin >> ch;
    switch(ch) {
        case 1: default:
            displayInfo();
            cin.ignore();
            getchar();
            break;
        case 2:
            inputClient();
            break;
        case 3:
            displayInfo();
            cout << "   Choose Key : ";
            cin >> key;
            deleteClient(key);
            break;
        case 4:
            displayInfo();
            cout << "   Choose Key : ";
            cin >> key;
            modifyClient(key);
            break;
        case 5:
            return false;
    }
    return true;
}