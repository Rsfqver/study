#include "LibraryManager.h"
#include <iostream>

using namespace std;

void displayMenu() {
    cout << "1. Sign Up\n";
    cout << "2. Login\n";
    cout << "3. Manage Members\n";
    cout << "4. Manage Books\n";
    cout << "5. Borrow/Return Book\n";
    cout << "6. Save All Data to File\n";
    cout << "7. Load All Data from File\n";
    cout << "8. Exit\n";
    cout << "Enter choice: ";
}

void handleChoice(int choice, LibraryManager& manager) {
    string username, password, name, email, title, author, filename;

    switch (choice) {
    case 1:
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter email: ";
        cin >> email;
        if (manager.signUp(username, password, name, email)) {
            cout << "Sign up successful!\n";
        }
        else {
            cout << "Username already exists.\n";
        }
        break;

    case 2:
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        if (manager.login(username, password)) {
            cout << "Login successful!\n";
        }
        else {
            cout << "Invalid username or password.\n";
        }
        break;

    case 3:
        cout << "1. List Members\n";
        cout << "2. View Borrowed Books of a Member\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            manager.listMembers();
        }
        else if (choice == 2) {
            cout << "Enter username: ";
            cin >> username;
            manager.listBorrowedBooks(username);
        }
        else {
            cout << "Invalid choice.\n";
        }
        break;

    case 4:
        cout << "1. Add Book\n";
        cout << "2. List Books\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            manager.addBook(title, author);
        }
        else if (choice == 2) {
            manager.listBooks();
        }
        else {
            cout << "Invalid choice.\n";
        }
        break;

    case 5:
        cout << "1. Borrow Book\n";
        cout << "2. Return Book\n";
        cout << "Enter choice: ";
        cin >> choice;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        if (choice == 1) {
            manager.borrowBook(username, title);
        }
        else if (choice == 2) {
            manager.returnBook(username, title);
        }
        else {
            cout << "Invalid choice.\n";
        }
        break;

    case 6:
        cout << "Enter filename to save all data: ";
        cin >> filename;
        manager.saveAllDataToFile(filename);
        cout << "Data saved to file successfully!\n";
        break;

    case 7:
        cout << "Enter filename to load all data: ";
        cin >> filename;
        manager.loadAllDataFromFile(filename);
        cout << "Data loaded from file successfully!\n";
        break;

    case 8:
        cout << "Exiting...\n";
        break;

    default:
        cout << "Invalid choice. Try again.\n";
        break;
    }
}

int main() {
    LibraryManager manager;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        handleChoice(choice, manager);
    } while (choice != 8);

    return 0;
}
