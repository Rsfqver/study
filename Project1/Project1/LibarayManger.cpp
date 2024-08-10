#include "LibraryManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool LibraryManager::signUp(const string& username, const string& password, const string& name, const string& email) {
    for (const auto& member : members) {
        if (member.getUsername() == username) {
            return false; // 이미 존재하는 사용자 이름
        }
    }
    members.emplace_back(username, password, name, email);
    return true;
}

bool LibraryManager::login(const string& username, const string& password) {
    for (const auto& member : members) {
        if (member.getUsername() == username && member.getPassword() == password) {
            return true;
        }
    }
    return false;
}

LibraryMember* LibraryManager::getMember(const string& username) {
    for (auto& member : members) {
        if (member.getUsername() == username) {
            return &member;
        }
    }
    return nullptr;
}

void LibraryManager::listMembers() const {
    cout << "List of members:\n";
    for (const auto& member : members) {
        cout << "Username: " << member.getUsername() << ", Name: " << member.getName() << ", Email: " << member.getEmail() << "\n";
    }
}

void LibraryManager::listBorrowedBooks(const string& username) const {
    for (const auto& member : members) {
        if (member.getUsername() == username) {
            cout << "Borrowed books by " << username << ":\n";
            for (const auto& book : member.getBorrowedBooks()) {
                cout << book << "\n";
            }
            return;
        }
    }
    cout << "Member not found.\n";
}

void LibraryManager::addBook(const string& title, const string& author) {
    books.emplace_back(title, author);
}

void LibraryManager::listBooks() const {
    cout << "List of books:\n";
    for (const auto& book : books) {
        cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Borrowed: " << (book.getIsBorrowed() ? "Yes" : "No") << "\n";
    }
}

void LibraryManager::borrowBook(const string& username, const string& title) {
    LibraryBook* book = nullptr;
    for (auto& b : books) {
        if (b.getTitle() == title) {
            book = &b;
            break;
        }
    }
    if (book && !book->getIsBorrowed()) {
        LibraryMember* member = getMember(username);
        if (member && member->borrowBook(title)) {
            book->borrowBook();
            cout << "Book borrowed successfully.\n";
        }
        else {
            cout << "Unable to borrow the book.\n";
        }
    }
    else {
        cout << "Book not available or already borrowed.\n";
    }
}

void LibraryManager::returnBook(const string& username, const string& title) {
    LibraryBook* book = nullptr;
    for (auto& b : books) {
        if (b.getTitle() == title) {
            book = &b;
            break;
        }
    }
    if (book && book->getIsBorrowed()) {
        LibraryMember* member = getMember(username);
        if (member && member->returnBook(title)) {
            book->returnBook();
            cout << "Book returned successfully.\n";
        }
        else {
            cout << "Unable to return the book.\n";
        }
    }
    else {
        cout << "Book not borrowed.\n";
    }
}

void LibraryManager::loadAllDataFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string section;
    while (getline(file, section)) {
        if (section == "[Members]") {
            string line;
            while (getline(file, line) && line != "[Books]") {
                stringstream ss(line);
                string username, password, name, email, borrowedBooks;

                getline(ss, username, ',');
                getline(ss, password, ',');
                getline(ss, name, ',');
                getline(ss, email, ',');
                getline(ss, borrowedBooks);

                LibraryMember member(username, password, name, email);
                stringstream booksStream(borrowedBooks);
                string book;
                while (getline(booksStream, book, '|')) {
                    member.borrowBook(book);
                }
                members.push_back(member);
            }
        }

        if (section == "[Books]") {
            string line;
            while (getline(file, line)) {
                stringstream ss(line);
                string title, author, isBorrowedStr;

                getline(ss, title, ',');
                getline(ss, author, ',');
                getline(ss, isBorrowedStr, ',');

                LibraryBook book(title, author);
                if (isBorrowedStr == "1") {
                    book.borrowBook();
                }
                books.push_back(book);
            }
        }
    }

    file.close();
}

void LibraryManager::saveAllDataToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    file << "[Members]\n";
    for (const auto& member : members) {
        file << member.getUsername() << "," << member.getPassword() << "," << member.getName() << "," << member.getEmail() << ",";
        for (const auto& book : member.getBorrowedBooks()) {
            file << book << "|";
        }
        file << "\n";
    }

    file << "[Books]\n";
    for (const auto& book : books) {
        file << book.getTitle() << "," << book.getAuthor() << "," << (book.getIsBorrowed() ? "1" : "0") << "\n";
    }

    file.close();
}
