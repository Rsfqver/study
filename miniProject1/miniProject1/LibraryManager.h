// LibraryManager.h
#pragma once
#include <vector>
#include "LibraryMember.h"
#include "LibraryBook.h"

using namespace std;

class LibraryManager {
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

   
    vector<LibraryMember>& getMembers() { return members; }
    vector<LibraryBook>& getBooks() { return books; }
};