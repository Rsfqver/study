// LibraryMember.cpp

#include "LibraryMember.h"

LibraryMember::LibraryMember(const string& username, const string& password, const string& name, const string& email)
    : username(username), password(password), name(name), email(email) {} //생성자들 정의

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
//auto 사용 //auto it 반복자 활용 //구현에 많은 시간을 사용함  //반복자란것은 벡터 컨테이너 안에서 위치를 가리켜주는것 포인터와 유사한개념 
bool LibraryMember::returnBook(const string& bookTitle) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {  //t != borrowedBooks.end(): it가 벡터의 끝을 지나지 않았는지 확인. borrowedBooks.end()는 벡터의 마지막 요소 다음을 가리키는 iterator를 반환
        if (*it == bookTitle) { //포인터와 비슷함 *주소값이 북타이틀과 같을때 즉 반납하는책이 맞는지 확인 
            borrowedBooks.erase(it); // 현재 iterator가 가리키고 있는 요소를 borrowedBooks 벡터에서 제거
            return true;
        }
    }
    return false; // 대출하지 않은 책
}
