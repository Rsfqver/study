#pragma once
#include <string>
#include <vector>
#include "LibraryMember.h"
#include "LibraryBook.h"
using namespace std;

class CSVSaver {
public:
    void saveMembers(const vector<LibraryMember>& members, const string& filename);
    void saveBooks(const vector<LibraryBook>& books, const string& filename);
    void saveBorrowedBooks(const vector<LibraryMember>& members, const string& filename); // 고객 대출 반납 정보 저장
}; 
