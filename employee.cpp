#include "employee.h" 


ostream& operator<< (ostream &os, const Employee & x){
    cout << "Name: " << x.name << "\t" << "Position: " << x.position << "\t" << "Age: " << x.age << endl;
    
    return os;
}

Employee::Employee(const Employee &e){
	name = new char[strlen(e.name)+1];
	strcpy(name, e.name);
	position = new char[strlen(e.position)+1];
	strcpy(position, e.position); 
	age = e.age;
}

Employee::Employee(char *n, char *p, int a){
  name = new char[strlen(n)+1];
  strcpy(name, n);
  position = new char[strlen(p)+1];
  strcpy(position, p);
  age = a;
}

Employee::~Employee(){
  delete []name;
  delete []position;
}

void Employee::setAge(int x){
  age = x;
}

void Employee::setName(char* n){
  if(strlen(n) != strlen(name)){
    delete []name;
    name = new char[strlen(n)+1];
  }
  strcpy(name, n);
}

void Employee::setPosition(char *p){
  if(strlen(p) != strlen(position)){
    delete []position;
    position = new char[strlen(p)+1];
  }  
  strcpy(position, p);
}


