#ifndef __CLIENT_H__
#define __CLIENT_H__
//����� �����
#include <iostream>

using namespace std;

class Client { //Ŭ���̾�Ʈ Ŭ���� ���� 
public:
    Client(int id = 0, string = "", string = "", string = "");

    string getName() const; //������ �޴� ���ڿ� ����(�̸�)
    void setName(string&); //������ ������ �ִ� ���ڿ� ���� 
    string getPhoneNumber() const;//������ �޴� ���ڿ� ����(�޴��� ��ȣ )
    void setPhoneNumber(string&);//������ ������ �ִ� ���ڿ� ���� 
    string getAddress() const;//������ �޴� ���ڿ� ����(�ּ�)
    void setAddress(string&);//������ ������ �ִ� ���ڿ� ���� 
    int id() const;
    bool operator==(const Client& other) const;

private: //�����ϰ� ����Ǵ� �������� �����̺�Ŭ������ ���Ͻ�Ŵ 
    int m_id;
    string m_name;
    string m_phoneNumber;
    string m_address;
};
#endif          // __CLIENT_H__

