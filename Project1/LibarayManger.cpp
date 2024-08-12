#include "LibraryManager.h"
#include <iostream>
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
            cout << "회원: " << username << "\n";
            for (const auto& book : member.getBorrowedBooks()) {
                cout << "책 이름: " << book << "\n";
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
        cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Borrowed: " << (book.getIsBorrowed() ? "대출 중" : "대출 가능 ") << "\n";
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
            cout << "대출 성공.\n";
        }
        else {
            cout << "대출 실패. 아이디 또는 책 제목을 정확히 입력 해주세요.\n";
        }
    }
    else {
        cout << "대출 중인 책입니다. 다른 책을 선택해주세요.\n";
    }
}

void LibraryManager::returnBook(const string& username, const string& title) {
    LibraryMember* member = getMember(username);
    if (member && member->returnBook(title)) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                book.returnBook(); // 이곳에서 반납 메서드 호출
                cout << "반납 성공.\n";
                return;
            }
        }
    }
    cout << "반납 실패. 아이디 또는 책 제목을 정확히 입력해 주세요.\n";
}


/*
void LibraryManager::returnBook(const string& username, const string& title) {
    LibraryMember* member = getMember(username);
    if (member && member->returnBook(title)) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                book.returnBook();
                cout << "반납 성공.\n";
                return;
            }
        }
    }
    cout << "반납 실패. 아이디 또는 책 제목을 정확히 입력 해주세요.\n";
}*/
