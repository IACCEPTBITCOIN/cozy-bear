#ifndef PACKAGE_H                       
#define PACKAGE_H

#include <iostream>
#include <string> 
#include <list>
#include "Customer.h" 

class Customer;                    // Forward Declaration, B apart of A 

class Package {

private:
    std::string name; 
    int id; 
    int maxPackages;
    std::list<Customer*>customers;                 // This template idea was derived with lecture Templates - Lecture 1 @ 31:14 of 6_templates_class.cpp, & example 5_templates_list_traversal.cpp
    std::list<Customer*>::iterator it;             // Used iterator for the destructor and etc for traversal
public: 
    Package() = default;                                         // Constructor EXPLAINED IN POLYMORPHISM LECTURE 2A
    ~Package();                                                 // Deconsturctor
    Package(const std::string& name, int id, int maxPackages); // parameterized constructor with pass by reference 

    std::string getName() const;                         // Accessor function 
    int getID() const;                                  // Accessor function
    int getMaxPackages() const;                        // Accessor function

    void setMaxPackages(int maxPackages);                 // Mutator function
    void setName(const std::string& name);               // Mutator function
    void setID(int id);                                 // Mutator function 

    friend std::ostream& operator<<(std::ostream &os, const Package& pkg);   // Overload to output data to console    // Overload concept with the direction of Project 2 by just replaced Store with Customer 
    friend std::ostream& operator<<(std::ostream &os, const std::list<Package*> &pkg);   
    friend bool operator==(const Package& p1, const Package& p2);
    friend bool operator==(const std::list<Package*>& p1, const std::list<Package*>& p2);

    // PHASE 2 CONTAINER FUNCTIONS 

    void display(std::list<Customer*>& o2) const;
};

#endif