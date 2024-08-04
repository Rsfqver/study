#ifndef __BOOK_H__  //����� �ߺ� ó�� ���� 
#define __BOOK_H__

#include <iostream>
using namespace std;

class Book {
	int id;
	char name[50];  // å�̸�
	char genre[50]; // �帣
	char author[50]; // ����
	int  rental; // ���⿩�� 
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

#endif //book ��� ���� ���� 
