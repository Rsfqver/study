#include "LibraryManager.h"
#include"Menu.h"
#include <iostream>

using namespace std;



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