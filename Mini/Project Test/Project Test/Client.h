#ifndef __CLIENT_H__
#define __CLIENT_H__
//헤더는 선언부
#include <iostream>

using namespace std;

class Client { //클라이언트 클래스 선언 
public:
    Client(int id = 0, string = "", string = "", string = "");

    string getName() const; //정보를 받는 문자열 선언(이름)
    void setName(string&); //정보를 저장해 주는 문자열 선언 
    string getPhoneNumber() const;//정보를 받는 문자열 선언(휴대폰 변호 )
    void setPhoneNumber(string&);//정보를 저장해 주는 문자열 선언 
    string getAddress() const;//정보를 받는 문자열 선언(주소)
    void setAddress(string&);//정보를 저장해 주는 문자열 선언 
    int id() const;
    bool operator==(const Client& other) const;

private: //선언하고 저장되는 정보들이 프라이빗클래스로 리턴시킴 
    int m_id;
    string m_name;
    string m_phoneNumber;
    string m_address;
};
#endif          // __CLIENT_H__

