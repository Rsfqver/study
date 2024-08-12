#include "LibraryManager.h"
#include <iostream>
using namespace std;

bool LibraryManager::signUp(const string& username, const string& password, const string& name, const string& email) {
    for (const auto& member : members) {
        if (member.getUsername() == username) {
            return false; // �̹� �����ϴ� ����� �̸�
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
            cout << "ȸ��: " << username << "\n";
            for (const auto& book : member.getBorrowedBooks()) {
                cout << "å �̸�: " << book << "\n";
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
        cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Borrowed: " << (book.getIsBorrowed() ? "���� ��" : "���� ���� ") << "\n";
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
            cout << "���� ����.\n";
        }
        else {
            cout << "���� ����. ���̵� �Ǵ� å ������ ��Ȯ�� �Է� ���ּ���.\n";
        }
    }
    else {
        cout << "���� ���� å�Դϴ�. �ٸ� å�� �������ּ���.\n";
    }
}

void LibraryManager::returnBook(const string& username, const string& title) {
    LibraryMember* member = getMember(username);
    if (member && member->returnBook(title)) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                book.returnBook(); // �̰����� �ݳ� �޼��� ȣ��
                cout << "�ݳ� ����.\n";
                return;
            }
        }
    }
    cout << "�ݳ� ����. ���̵� �Ǵ� å ������ ��Ȯ�� �Է��� �ּ���.\n";
}


/*
void LibraryManager::returnBook(const string& username, const string& title) {
    LibraryMember* member = getMember(username);
    if (member && member->returnBook(title)) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                book.returnBook();
                cout << "�ݳ� ����.\n";
                return;
            }
        }
    }
    cout << "�ݳ� ����. ���̵� �Ǵ� å ������ ��Ȯ�� �Է� ���ּ���.\n";
}*/
