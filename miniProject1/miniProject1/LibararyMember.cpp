#include "LibraryMember.h"

LibraryMember::LibraryMember(const string& username, const string& password, const string& name, const string& email)
    : username(username), password(password), name(name), email(email) {}

string LibraryMember::getUsername() const {
    return username;
}

string LibraryMember::getPassword() const {
    return password;
}

string LibraryMember::getName() const {
    return name;
}

string LibraryMember::getEmail() const {
    return email;
}

const vector<string>& LibraryMember::getBorrowedBooks() const {
    return borrowedBooks;
}

bool LibraryMember::borrowBook(const string& bookTitle) {
    for (const auto& book : borrowedBooks) {
        if (book == bookTitle) {
            return false; // 이미 대출한 책
        }
    }
    borrowedBooks.push_back(bookTitle);
    return true;
}

bool LibraryMember::returnBook(const string& bookTitle) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if (*it == bookTitle) {
            borrowedBooks.erase(it);
            return true;
        }
    }
    return false; // 대출하지 않은 책
}