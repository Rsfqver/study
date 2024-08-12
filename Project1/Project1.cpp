#include "LibraryManager.h"
#include "CSVLoader.h"
#include "CSVSaver.h"
#include "Menu.h"
#include <iostream>

using namespace std;

int main() {
    LibraryManager manager; // LibraryManager 객체 생성
    CSVLoader loader; // CSVLoader 객체 생성
    CSVSaver saver; // CSVSaver 객체 생성

    // 데이터 로드
    loader.loadMembers(manager.getMembers(), "members.txt"); // 회원 데이터 로드
    loader.loadBooks(manager.getBooks(), "books.txt"); // 도서 데이터 로드

    int choice;
    do {
        displayMenu(); // 메뉴 출력
        cin >> choice; // 사용자 입력
        handleChoice(choice, manager); // 선택한 메뉴에 따른 처리

        // 데이터 저장
        saver.saveMembers(manager.getMembers(), "members.txt"); // 회원 데이터 저장
        saver.saveBooks(manager.getBooks(), "books.txt"); // 도서 데이터 저장

    } while (choice != 4); // 선택지가 4가 아닐 경우 계속 반복

    return 0; // 프로그램 종료
}
