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

	Employee JK((char*)"Jan Kowalski", (char*)"salesman", 28);
	Employee AN((char*)"Adam Nowak", (char*)"storekeeper", 54);
 	Employee AZ((char*)"Anna Zaradna", (char*)"secretary", 32);

	database.Add(761028073, JK);
	database.Add(510212881, AN);
	database.Add(730505129, AZ);

	cout << database << endl;											//Print database

	Map<ID, Employee> newDatabase = database;

	Employee* pE;	
	pE = newDatabase.find(510212881); //Find employee using its ID
	pE->setPosition((char*)"salesman");//Modify the position
	pE = newDatabase.find(761028073);									//Find employee using its ID
	pE->setAge(29);				//Modify the
	database = newDatabase;	
	cout << newDatabase << endl;											//Print original
	Book b1((char*)"Jan Adam", (char*)"Dramat", 211, 0);
	library.Add((string)"Romeo", b1);
									//Database of employees
        cout << library; 
}
