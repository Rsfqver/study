#pragma once
#include <string>
using namespace std;

class LibraryBook {
private:
    string title;
    string author;
    bool isBorrowed;

public:
    // �����ڿ� �⺻���� �߰�
    LibraryBook(const string& title, const string& author, bool isBorrowed = false);

    string getTitle() const;
    string getAuthor() const;
    bool getIsBorrowed() const;
    void borrowBook();
    void returnBook();
};
