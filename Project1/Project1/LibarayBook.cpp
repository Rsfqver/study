// LibraryBook.cpp

#include "LibraryBook.h"

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
