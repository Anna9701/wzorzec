#include "bib.h"

Book::Book(char *a, char *c, int n, bool s){
	author = new char[strlen(a)+1];
	strcpy(author, a);
	cathegory = new char[strlen(c)+1];
	strcpy(cathegory, c);
	number = n;
	status = s;
}

Book::Book(const Book &b){
	author = new char[strlen(b.author)+1];
	strcpy(author, b.author);
	cathegory = new char[strlen(b.cathegory)+1];
	strcpy(cathegory, b.cathegory);
	number = b.number;
	status = b.status;
}

Book::~Book(){
	delete []author;
	delete []cathegory;
}

ostream& operator << (ostream &os, const Book &b){
	cout << "Autor: " << b.author << endl;
	cout << "Kategoria: " << b.cathegory << endl;
	cout << "Ilosc stron: " << b.number << endl << "Status: ";
	if(b.status)
		cout << "Na polce" << endl;
	else
		cout << "Wypozyczona" << endl;

	return os;
}

void Book::setAuthor(char* a){
	if(strlen(a) != strlen(author)){
		delete []author;
		author = new char[strlen(a)+1];
	}
	strcpy(author, a);
}

void Book::setCat(char* c){
	if(strlen(c) != strlen(cathegory)){
		delete []cathegory;
		cathegory = new char[strlen(c)+1];
	}
	strcpy(cathegory, c);
}

void Book::setNumber(int n){
	number = n;
}

void Book::setStatus(bool s){
	status = s;
}
