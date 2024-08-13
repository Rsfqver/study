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
        
        books.emplace_back(title, author, isBorrowed);
    }
    file.close();
}


void CSVLoader::loadBorrowedBooks(vector<LibraryMember>& members, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username, bookTitle;

            getline(ss, username, ',');
            getline(ss, bookTitle, ',');

            for (auto& member : members) {
                if (member.getUsername() == username) {
                    member.borrowBook(bookTitle); // 대출된 책 목록에 추가
                }
            }
        }
        file.close();
    }
    else {
        cerr << "Could not open file for reading: " << filename << endl;
    }
}