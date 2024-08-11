#pragma once
#include <vector>
#include "LibraryMember.h"
#include "LibraryBook.h"
//관리 구성 헤더 그렇기에 구성한 다른 헤더들이 다들어있고 stl벡터도같이있음 
using namespace std;

class LibraryManager 
{
private:
    vector<LibraryMember> members;
    vector<LibraryBook> books;

public:
    bool signUp(const string& username, const string& password, const string& name, const string& email);
    bool login(const string& username, const string& password);
    LibraryMember* getMember(const string& username);
    void listMembers() const;
    void listBorrowedBooks(const string& username) const;
    void addBook(const string& title, const string& author);
    void listBooks() const;
    void borrowBook(const string& username, const string& title);
    void returnBook(const string& username, const string& title);

    //------------------------별도로 분리해봐야될듯?
    void loadAllDataFromFile(const string& filename); //파일 세이브
    void saveAllDataToFile(const string& filename) const; //파일 저장 
};
