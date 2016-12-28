#ifndef _EMPLOYEE_H_
 #define _EMPLOYEE_H_
 #include <string>
 #include <string.h>
 #include <iostream>
 using namespace std;

 class Employee{
  public:
   Employee(char *, char* , int);
   Employee(const Employee&);
   ~Employee();

   void setAge(int);
   void setName(char*); 
   void setPosition(char*);
   friend ostream& operator<< (ostream&, const Employee&);
  private:
   char *name;
   char *position;
   int age;	
 };

#endif
