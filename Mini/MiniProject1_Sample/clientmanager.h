#ifndef __CLIENT_MANAGER_H__
#define __CLIENT_MANAGER_H__
//헤더는 선언부
#include <map>
#include <vector>
#include "client.h"
//1. 클라이언트(고객)층을 구현후에 만들어낸 메뉴와 파일 구현 헤더. 고객관리와 메뉴 인터페이스 구현 
using namespace std;

class ClientManager { //클라이언트 매니저 클래스 선언 
  public:
      ClientManager(); //생성자
      ~ClientManager();//소멸자 

      void inputClient( );//고객 정보 입력 
      void addClient(Client*); //고객의 정보를 리스트에 삽입하는 생성자 
      void deleteClient(int);//고객 정보 지움
      void modifyClient(int); //고객 정보 수정?
      Client* search(int); //고객 검색 
      int makeId();//아이디 생성 
      void displayInfo();//고객 정보확인 
      vector<string> parseCSV(istream&, char); //파일 읽고 분석하는 생성자 구현?

      bool displayMenu();//디스플레이 확인 

  private:
      map<int, Client*> clientList; //map은 자료를 유일한 key와 하나의 value 쌍으로 저장하는 자료구조 고객 리스트에 자료형으로 만든 고객을 저장 
};

#endif    // __CLIENT_MANAGER_H__
