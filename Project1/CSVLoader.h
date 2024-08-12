// CSVLoader.h
#pragma once
#include <string>
#include <vector>
#include "LibraryMember.h"
#include "LibraryBook.h"

using namespace std;

class CSVLoader {
public:
    void loadMembers(vector<LibraryMember>& members, const string& filename); // const 참조로 유지
    void loadBooks(vector<LibraryBook>& books, const string& filename); // const 참조로 유지
};
