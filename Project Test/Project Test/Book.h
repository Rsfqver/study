#include <iostream>
#include <string>
#include <list>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

class Book {
	int id;
	char name[50];  // å�̸�
	char genre[50]; // �帣
	char author[50]; // ����
	int  rental; // ���⿩�� 
public:
	Book(int _id, const char _name[], const char _genre[], const char _author[]) {
		
	}
	Book() {};
	~Book() {};
	char* geBooktName();
	char* getGenre();
	char* getAuthor();
	int getId();
	const char* getRental();
	void setRental(int rental);
};
