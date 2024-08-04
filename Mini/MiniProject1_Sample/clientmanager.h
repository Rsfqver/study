#ifndef __CLIENT_MANAGER_H__
#define __CLIENT_MANAGER_H__
//����� �����
#include <map>
#include <vector>
#include "client.h"
//1. Ŭ���̾�Ʈ(��)���� �����Ŀ� ���� �޴��� ���� ���� ���. �������� �޴� �������̽� ���� 
using namespace std;

class ClientManager { //Ŭ���̾�Ʈ �Ŵ��� Ŭ���� ���� 
  public:
      ClientManager(); //������
      ~ClientManager();//�Ҹ��� 

      void inputClient( );//�� ���� �Է� 
      void addClient(Client*); //���� ������ ����Ʈ�� �����ϴ� ������ 
      void deleteClient(int);//�� ���� ����
      void modifyClient(int); //�� ���� ����?
      Client* search(int); //�� �˻� 
      int makeId();//���̵� ���� 
      void displayInfo();//�� ����Ȯ�� 
      vector<string> parseCSV(istream&, char); //���� �а� �м��ϴ� ������ ����?

      bool displayMenu();//���÷��� Ȯ�� 

  private:
      map<int, Client*> clientList; //map�� �ڷḦ ������ key�� �ϳ��� value ������ �����ϴ� �ڷᱸ�� �� ����Ʈ�� �ڷ������� ���� ���� ���� 
};

#endif    // __CLIENT_MANAGER_H__
