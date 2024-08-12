#pragma once
#include <string>
#include <vector>
using namespace std;

class LibraryMember {
private:
    string username;
    string password;
    string name;
    string email;
    vector<string> borrowedBooks;

public:
    LibraryMember(const string& username, const string& password, const string& name, const string& email);

    string getUsername() const;
    string getPassword() const;
    string getName() const;
    string getEmail() const;

    const vector<string>& getBorrowedBooks() const;
    bool borrowBook(const string& bookTitle);
    bool returnBook(const string& bookTitle);
};
