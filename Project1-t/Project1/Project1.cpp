#include "LibraryManager.h"
#include "Menu.h"
#include <iostream>
//이렇게 다 분리하여  메인함수는 최적화함
using namespace std;
int main() 
{
    LibraryManager manager;
    int choice;
    manager.loadAllDataFromFile("data.txt");
   
    do 
  {
        displayMenu();
        cin >> choice;
        handleChoice(choice, manager);
        
    } while (choice != 4); // 선택지를 4로 변경 (Exit) 4가아니라면 데이터는 꾸준히 돌아감 
    
    manager.saveAllDataToFile("data.txt"); //데이터 쓰기 
    
    
    

    return 0;
}
