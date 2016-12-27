#include "employee.h" 


ostream& operator<< (ostream &os, const Employee & x){
    cout << "Name: " << x.name << "\t" << "Position: " << x.position << "\t" << "Age: " << x.name << endl;

}
