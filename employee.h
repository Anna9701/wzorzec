#ifndef _EMPLOYEE_H_
 #define _EMPLOYEE_H_
 #include <string>
 #include <iostream>
 using namespace std;

 class Employee{
  public:
   Employee(string, string, int);
   ~Employee();

   friend ostream& operator<< (ostream&, const Employee&);
  private:
   string name;
   string position;
   int age;	
 };

#endif
