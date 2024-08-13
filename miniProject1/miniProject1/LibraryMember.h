// LibraryMember.h
//1.처음 생성한 작업 파일
#pragma once
#include <string> //문자를 담는 헤더
#include <vector> //객체 동적 할당 문자열을 동적으로 help스택에 저장 
//공통적으로 const를 선언해서 문자가 안바뀌게끔 했음 .
using namespace std;

class LibraryMember
{ //클래스 선언 
private:
    string username; //유저 관리 정보들 
    string password;
    string name;
    string email;
    vector<string> borrowedBooks; // 책 제목을 저장

public://생성자들의 매개변수 
    LibraryMember(const string& username, const string& password, const string& name, const string& email); //입력되는 문자를 받을  함수선언들

    string getUsername() const; //생성자들 
    string getPassword() const;
    string getName() const;
    string getEmail() const;

    const vector<string>& getBorrowedBooks() const; //도서생성 

    bool borrowBook(const string& bookTitle);
    bool returnBook(const string& bookTitle);
};
