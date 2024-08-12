// CSVLoader.cpp
#include "CSVLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

void CSVLoader::loadMembers(vector<LibraryMember>& members, const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string username, password, name, email;

        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');

        // LibraryMember 생성자 호출
        members.emplace_back(username, password, name, email);
    }
    file.close();
}

void CSVLoader::loadBooks(vector<LibraryBook>& books, const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string title, author, isBorrowedStr;

        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, isBorrowedStr, ',');

        bool isBorrowed = (isBorrowedStr == "1");
        // LibraryBook 생성자 호출
        books.emplace_back(title, author, isBorrowed);
    }
    file.close();
}
