// Menu.h
//작성하다 보니 메뉴를 관리하는 별도의 파일로 관리해나가는것이 더욱 괜찮을거란 생각이들어서 분리함 마지막으로작성된 헤더 
#pragma once
#include "LibraryManager.h"

void displayMenu();
void handleChoice(int choice, LibraryManager& manager); //참조 활용  겹쳐서 복사가 되어 프로그램이 꼬일경우를방지했음 

