// LibraryMember.cpp

#include "LibraryMember.h"

LibraryMember::LibraryMember(const string& username, const string& password, const string& name, const string& email)
    : username(username), password(password), name(name), email(email) {} //�����ڵ� ����

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
            return false; // �̹� ������ å
        }
    }
    borrowedBooks.push_back(bookTitle);
    return true;
}
//auto ��� //auto it �ݺ��� Ȱ�� //������ ���� �ð��� �����  //�ݺ��ڶ����� ���� �����̳� �ȿ��� ��ġ�� �������ִ°� �����Ϳ� �����Ѱ��� 
bool LibraryMember::returnBook(const string& bookTitle) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {  //t != borrowedBooks.end(): it�� ������ ���� ������ �ʾҴ��� Ȯ��. borrowedBooks.end()�� ������ ������ ��� ������ ����Ű�� iterator�� ��ȯ
        if (*it == bookTitle) { //�����Ϳ� ����� *�ּҰ��� ��Ÿ��Ʋ�� ������ �� �ݳ��ϴ�å�� �´��� Ȯ�� 
            borrowedBooks.erase(it); // ���� iterator�� ����Ű�� �ִ� ��Ҹ� borrowedBooks ���Ϳ��� ����
            return true;
        }
    }
    return false; // �������� ���� å
}
