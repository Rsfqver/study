// Menu.cpp

#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;

void displayMenu() {
    cout << "1. ȸ�� �޴�\n";
    cout << "2. ������ �޴�\n";
    cout << "3. �� �޴�\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}
//���� �ҷ����� �бⰡ ����� ���۾ȵǼ� �׳� ��θ� �����ؼ� ����Ͽ��� 
void handleChoice(int choice, LibraryManager& manager) { 
    
    // ������ �ε�  
 //�����ͷε�//���ڿ� �� ������ ���̺귯���Ŵ��� Ŭ������ ������ �Է¹޴� ���ڿ� �����Ŵ 
    if (choice == 1) {
       
        // ȸ�� �޴�
        int memberChoice; //��ȣ �Է� 
        do {
            cout << "\n--- ȸ�� �޴� ---\n";
            cout << "1. ȸ������\n";
            cout << "2. �α���\n";
            cout << "3. ���� ���\n";
            cout << "4. ���� ����\n";
            cout << "5. ���� �ݳ�\n";
            cout << "6. ���� �޴���\n";
            cout << "�޴��� �������ּ���: ";
            cin >> memberChoice;

            if (memberChoice == 1) {
                // Sign Up
                string username, password, name, email;
                cout << "�г����� �Է����ּ���: ";
                cin >> username;
                cout << "��й�ȣ ����: ";
                cin >> password;
                cout << "�̸�: ";
                cin >> name;
                cout << "�̸���: ";
                cin >> email;
                if (manager.signUp(username, password, name, email)) {
                    cout << "ȸ�������� ���������� ����Ǿ����ϴ�.!\n";
                }
                else {
                    cout << "ȸ�����Կ� �����߽��ϴ�..\n";
                }
            }
            else if (memberChoice == 2) {
                // Login
                string username, password;
                cout << "�г����� �Է����ּ���: ";
                cin >> username;
                cout << "��й�ȣ �Է�: ";
                cin >> password;
                if (manager.login(username, password)) {
                    cout << "Login successful!\n";
                }
                else {
                    cout << "���̵� �Ǵ� ��й�ȣ�� Ʋ�Ƚ��ϴ�.\n";
                }
            }
            else if (memberChoice == 3) {
                // List Books
                manager.listBooks();
            }
            else if (memberChoice == 4) {
                // Borrow Book
                string username, title;
                cout << "���̵� �Է��ϼ��� ";
                cin >> username;
                cout << " å�������� �����ּ��� ";
                cin.ignore();
                getline(cin, title);
                manager.borrowBook(username, title);
            }
            else if (memberChoice == 5) {
                // Return Book
                string username, title;
                cout << "���̵� �Է��ϼ��� ";
                cin >> username;
                cout << "å�������� �����ּ���: ";
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
        // ������ �޴�
        
        int adminChoice;
        do {
            cout << "\n--- ������ �޴� ---\n";
            cout << "1. ȸ�� ��� \n";
            cout << "2. ���� ���� �� ���\n";
            cout << "3. ���� �߰�\n";
            cout << "4. ���� ��� \n";
            cout << "5. ���� �޴���\n";
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
    cout << "Exiting... ���α׷��� �����մϴ�.\n";
    
        exit(1);
    }
    else {
        cout << "Invalid choice. Try again.\n";
    }
   
}
