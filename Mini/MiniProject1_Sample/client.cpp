#include "client.h" //고객 클래스 

#include <iostream>

using namespace std;

Client::Client(int id, string name, string phoneNumber, string address)
          : m_id(id), m_name(name), m_phoneNumber(phoneNumber), m_address(address)
{
}

string Client::getName() const
{
    return m_name;
}

void Client::setName(string& name)
{
    m_name = name;
}

string Client::getPhoneNumber() const
{
    return m_phoneNumber;
}

void Client::setPhoneNumber(string& phoneNumber)
{
    m_phoneNumber = phoneNumber;
}

string Client::getAddress() const
{
    return m_address;
}

void Client::setAddress(string& address)
{
    m_address = address;
}

int Client::id() const
{
    return m_id;
}

// Define copy assignment operator.
bool Client::operator==(const Client &other) const {
    return (this->m_name == other.m_name);
}


//별도로 분석할만한 구간은 아니였음  선언된 헤더를 저장하고 리턴하는 구현화를 행한것이기때문에 
//생성자들의 리턴을 잡아준것이기 때문