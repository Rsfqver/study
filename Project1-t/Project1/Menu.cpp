// Menu.cpp

#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu() {
    cout << "1. 회원 메뉴\n";
    cout << "2. 관리자 메뉴\n";
    cout << "3. 빈 메뉴\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}
//파일 불러오고 읽기가 제대로 동작안되서 그냥 경로를 지정해서 사용하였음 
void handleChoice(int choice, LibraryManager& manager) { 
    
    // 데이터 로드  
 //데이터로드//인자에 다 구성된 라이브러리매니저 클래스를 참조헤 입력받는 숫자와 연결시킴 
    if (choice == 1) {
       
        // 회원 메뉴
        int memberChoice; //번호 입력 
        do {
            cout << "\n--- 회원 메뉴 ---\n";
            cout << "1. 회원가입\n";
            cout << "2. 로그인\n";
            cout << "3. 도서 목록\n";
            cout << "4. 도서 대출\n";
            cout << "5. 도서 반납\n";
            cout << "6. 상위 메뉴로\n";
            cout << "메뉴를 선택헤주세요: ";
            cin >> memberChoice;

            if (memberChoice == 1) {
                // Sign Up
                string username, password, name, email;
                cout << "닉네임을 입력해주세요: ";
                cin >> username;
                cout << "비밀번호 설정: ";
                cin >> password;
                cout << "이름: ";
                cin >> name;
                cout << "이메일: ";
                cin >> email;
                if (manager.signUp(username, password, name, email)) {
                    cout << "회원가입이 성공적으로 진행되었습니다.!\n";
                }
                else {
                    cout << "회원가입에 실패했습니다..\n";
                }
            }
            else if (memberChoice == 2) {
                // Login
                string username, password;
                cout << "닉네임을 입력해주세요: ";
                cin >> username;
                cout << "비밀번호 입력: ";
                cin >> password;
                if (manager.login(username, password)) {
                    cout << "Login successful!\n";
                }
                else {
                    cout << "아이디 또는 비밀번호가 틀렸습니다.\n";
                }
            }
            else if (memberChoice == 3) {
                // List Books
                manager.listBooks();
            }
            else if (memberChoice == 4) {
                // Borrow Book
                string username, title;
                cout << "아이디를 입력하세요 ";
                cin >> username;
                cout << " 책의제목을 적어주세요 ";
                cin.ignore();
                getline(cin, title);
                manager.borrowBook(username, title);
            }
            else if (memberChoice == 5) {
                // Return Book
                string username, title;
                cout << "아이디를 입력하세요 ";
                cin >> username;
                cout << "책의제목을 적어주세요: ";
                cin.ignore();
                getline(cin, title);
                manager.returnBook(username, title);
            }
            else if (memberChoice != 6) {
                cout << "Invalid choice. Try again.\n";
            }
        } while (memberChoice != 6);
    }
    else if (choice == 2) {
        // 관리자 메뉴
        
        int adminChoice;
        do {
            cout << "\n--- 관리자 메뉴 ---\n";
            cout << "1. 회원 명단 \n";
            cout << "2. 도서 대출 고객 명단\n";
            cout << "3. 도서 추가\n";
            cout << "4. 도서 목록 \n";
            cout << "5. 상위 메뉴로\n";
            cout << "Enter choice: ";
            cin >> adminChoice;

            if (adminChoice == 1) {
                // List Members
                manager.listMembers();
            }
            else if (adminChoice == 2) {
                // View Borrowed Books of a Member
                string username;
                cout << "Enter username: ";
                cin >> username;
                manager.listBorrowedBooks(username);
            }
            else if (adminChoice == 3) {
                // Add Book
                string title, author;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                manager.addBook(title, author);
            }
            else if (adminChoice == 4) {
                // List Books
                manager.listBooks();
            }
            else if (adminChoice != 5) {
                cout << "Invalid choice. Try again.\n";
            }
        } while (adminChoice != 5);
    }
    else if (choice == 4) {
    cout << "Exiting... 프로그램을 종료합니다.\n";
    
        exit(1);
    }
    else {
        cout << "Invalid choice. Try again.\n";
    }
   
}
