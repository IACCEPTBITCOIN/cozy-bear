#include "Store.h"

Store::Store() : name("noname"), employees(0) {}

Store::Store(const std::string &name, int employees) : name(name), employees(employees) {}

std::string Store::getName() const              
{
    return name;
}

int Store::getEmployees() const                     //MICHAEL
{
    return employees;
}


void Store::setName(const std::string &newname)                     //MICAHEL
{
    name = newname;
}
void Store::setEmployees(int num)                       
{
    employees = num;
}

void Store::print() const 
{
    std::cout << "Company: " << name << ", Employees: " << employees << std::endl;
}

bool compare(const Store &o1, const Store &o2, bool comparator)
{                                                                        // Explained in documentation, found from pseduocode 9 
    if(comparator == true) {
        return o1.getEmployees() <= o2.getEmployees();
    } else  {
        return o1.getEmployees() > o2.getEmployees();        // COMPARES EMPLOYEE COUNT OF BOTH STORES
    }                                   //MICHAEL
}

bool operator==(const Store &o1, const Store&o2 ) {                  // equivalence function
    return o1.name == o2.name && o1.employees == o2.employees; // essentially, if o1.name == o2.name & o1. # employees = o2. # employees
}                                                           // return bool true(1) if conditions are met, if not false(0)   //MICAHEL 
                                                            // From "Operator Overloading - Lecture 2" 29:48

std::ostream& operator<<(std::ostream &os, const Store &store) { // ONLY RUNS AS A FRIEND AFTER OVERLOADING << 
    os << "Company Name: " << store.name                               // Needed to access string outputs to the console. 
    << ", Employees: " << store.employees <<"\n";                     //MICHAEL  
    return os;
}

