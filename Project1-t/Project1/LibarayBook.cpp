// LibraryBook.cpp

#include "LibraryBook.h"
//별거없이 북 헤더에 선언한 생성자들의 정의와 리턴값을 지정 
LibraryBook::LibraryBook(const string& title, const string& author)
    : title(title), author(author), isBorrowed(false) {}

string LibraryBook::getTitle() const {
    return title;
}

string LibraryBook::getAuthor() const {
    return author;
}

bool LibraryBook::getIsBorrowed() const {
    return isBorrowed;
}

void LibraryBook::borrowBook() {
    isBorrowed = true;
}

void LibraryBook::returnBook() {
    isBorrowed = false;
}
