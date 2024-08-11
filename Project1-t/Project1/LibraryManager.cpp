#include <LibraryManager.h>
#include <fstream>
#include <sstream>

using namespace std;

void LibraryManager::displayMainMenu() {
    cout << "1. Member Management\n";
    cout << "2. Book Management\n";
    cout << "3. Exit\n";
    cout << "Enter choice: ";
}

void LibraryManager::displayMemberMenu() {
    cout << "1. Sign Up\n";
    cout << "2. Login\n";
    cout << "3. List Members\n";
    cout << "4. View Borrowed Books of a Member\n";
    cout << "5. Back to Main Menu\n";
    cout << "Enter choice: ";
}

void LibraryManager::displayBookMenu() {
    cout << "1. Add Book\n";
    cout << "2. List Books\n";
    cout << "3. Borrow Book\n";
    cout << "4. Return Book\n";
    cout << "5. Back to Main Menu\n";
    cout << "Enter choice: ";
}

void LibraryManager::handleMainChoice(int choice) {
    int subChoice;

    if (choice == 1) {
        do {
            displayMemberMenu();
            cin >> subChoice;
            handleMemberChoice(subChoice);
        } while (subChoice != 5);
    }
    else if (choice == 2) {
        do {
            displayBookMenu();
            cin >> subChoice;
            handleBookChoice(subChoice);
        } while (subChoice != 5);
    }
    else if (choice == 3) {
        cout << "Exiting...\n";
    }
    else {
        cout << "Invalid choice. Try again.\n";
    }
}

void LibraryManager::handleMemberChoice(int choice) {
    string username, password, name, email;

    if (choice == 1) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter email: ";
        cin >> email;
        if (signUp(username, password, name, email)) {
            cout << "Sign up successful!\n";
        }
        else {
            cout << "Username already exists.\n";
        }
    }
    else if (choice == 2) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        if (login(username, password)) {
            cout << "Login successful!\n";
        }
        else {
            cout << "Invalid username or password.\n";
        }
    }
    else if (choice == 3) {
        listMembers();
    }
    else if (choice == 4) {
        cout << "Enter username: ";
        cin >> username;
        listBorrowedBooks(username);
    }
    else if (choice == 5) {
        cout << "Returning to Main Menu...\n";
    }
    else {
        cout << "Invalid choice. Try again.\n";
    }
}

void LibraryManager::handleBookChoice(int choice) {
    string title, author, username;

    if (choice == 1) {
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        addBook(title, author);
    }
    else if (choice == 2) {
        listBooks();
    }
    else if (choice == 3) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        borrowBook(username, title);
    }
    else if (choice == 4) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        returnBook(username, title);
    }
    else if (choice == 5) {
        cout << "Returning to Main Menu...\n";
    }
    else {
        cout << "Invalid choice. Try again.\n";
    }
}
