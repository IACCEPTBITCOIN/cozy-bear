#ifndef STORE_H
#define STORE_H

#include <iostream> 
#include <string> 

class Store
{
private:
    std::string name;           // initialize string data set for Company Names   -MICHAEL
    int employees;                  // initialize numeric data set for # of employees 
public:
    
Store();                                                     // default constructor initialization 
Store(const std::string &name, int employees);   //parameterized constructor 

// Accessor functions
std::string getName() const;   
int getEmployees() const;                              //MICHAEL

// Mutator Functions 
void setName(const std::string &newname);
void setEmployees(int num);                         //MICHAEL
// Print Functions 
void print() const;                                 //MICHAEL

friend std::ostream& operator<<(std::ostream &os, const Store &store); // Changed to be defined in .cpp instead. 

friend bool operator== (const Store &o1, const Store &o2);  // Equivalance function // CHANGED TO BE DEFINED IN .CPP INSTEAD 

};

// Non-Member Functions 
bool compare(const Store &o1,const Store &o2,bool comparator);



#endif