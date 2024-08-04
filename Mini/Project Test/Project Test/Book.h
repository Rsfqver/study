#ifndef __BOOK_H__  //헤더의 중복 처리 방지 
#define __BOOK_H__

#include <iostream>
using namespace std;

class Book {
	int id;
	char name[50];  // 책이름
	char genre[50]; // 장르
	char author[50]; // 저자
	int  rental; // 대출여부 
public:
	Book(int _id, const char _name[], const char _genre[], const char _author[]) 
	{
		id = _id;
		rental = 0;
		strcpy_s(name, _name);
		strcpy_s(genre, _genre);
		strcpy_s(author, _author);
	
		}
	Book() {};
	~Book() {};
	char* getBooktName();
	char* getGenre();
	char* getAuthor();
	int getid();
	const char* getRental();
	void setRental(int rental);
};

#endif //book 헤더 종료 선언 
