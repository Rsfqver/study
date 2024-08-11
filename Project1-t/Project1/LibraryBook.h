// LibraryBook.h
//순서상으로 3번째에 추가한 헤더다 처음엔 메니저 헤더에 책관리까지 다있었기 때문 
#pragma once
#include <string>
//별도로 표시할만한거없음 
using namespace std;

class LibraryBook 
{
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
