// LibraryBook.h

#pragma once
#include <string>

using namespace std;

class LibraryBook {
private:
    string title;
    string author;
    bool isBorrowed;

public:
    LibraryBook(const string& title, const string& author);

    string getTitle() const;
    string getAuthor() const;
    bool getIsBorrowed() const;
    void borrowBook();
    void returnBook();
};
