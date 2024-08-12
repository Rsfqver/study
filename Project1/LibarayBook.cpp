#include "LibraryBook.h"

LibraryBook::LibraryBook(const string& title, const string& author, bool isBorrowed)
    : title(title), author(author), isBorrowed(isBorrowed) {}

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
