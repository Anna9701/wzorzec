#include <iostream>
#include "bib.h"
#include "employee.h"													//Defines class Employee
#include "map.h"														//Defines template Map<Key,Value>

using namespace std;

int main(void)
{
	typedef unsigned int ID; 											//Identification number of Employee
	Map<ID, Employee> database;
        Map<string, Book> library;
	Employee s((char*)"adam Nowak", (char *)"sprzedawca", 21);
        database.Add(212121, s);
	Book b1((char*)"Jan Adam", (char*)"Dramat", 211, 0);
        Title t1((char*)"Romeo");
	library.Add((string)"Romeo", b1);
	cout << database;									//Database of employees
        cout << library; 
}
