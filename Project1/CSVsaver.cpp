#include "CSVSaver.h"
#include <fstream>
#include <iostream>
using namespace std;
void CSVSaver::saveMembers(const vector<LibraryMember>& members, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& member : members) {
            file << member.getUsername() << ","
                << member.getPassword() << ","
                << member.getName() << ","
                << member.getEmail() << "\n";
        }
        file.close();
    }
    else {
        cerr << "Could not open file for writing: " << filename << endl;
    }
}

void CSVSaver::saveBooks(const vector<LibraryBook>& books, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& book : books) {
            file << book.getTitle() << ","
                << book.getAuthor() << ","
                << (book.getIsBorrowed() ? "1" : "0") << "\n"; // 1 for borrowed, 0 for not borrowed
        }
        file.close();
    }
    else {
        cerr << "Could not open file for writing: " << filename << endl;
    }
}
