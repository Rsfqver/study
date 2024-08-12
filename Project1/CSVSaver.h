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
};
