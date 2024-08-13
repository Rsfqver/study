// LibraryMember.h
//1.ó�� ������ �۾� ����
#pragma once
#include <string> //���ڸ� ��� ���
#include <vector> //��ü ���� �Ҵ� ���ڿ��� �������� help���ÿ� ���� 
//���������� const�� �����ؼ� ���ڰ� �ȹٲ�Բ� ���� .
using namespace std;

class LibraryMember
{ //Ŭ���� ���� 
private:
    string username; //���� ���� ������ 
    string password;
    string name;
    string email;
    vector<string> borrowedBooks; // å ������ ����

public://�����ڵ��� �Ű����� 
    LibraryMember(const string& username, const string& password, const string& name, const string& email); //�ԷµǴ� ���ڸ� ����  �Լ������

    string getUsername() const; //�����ڵ� 
    string getPassword() const;
    string getName() const;
    string getEmail() const;

    const vector<string>& getBorrowedBooks() const; //�������� 

    bool borrowBook(const string& bookTitle);
    bool returnBook(const string& bookTitle);
};
