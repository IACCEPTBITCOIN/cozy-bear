#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string> 
#include <list> 
#include "Package.h"                                      // If i am pointing to a package, we need to include package.h (A includes B & B includes A)  

/*
CORE MEMBERS AND DATA MEMBERS HAVE BEEN ADDED FOR CUSTOMER BY MICHAEL BYRD

I decided to use vector because it seems like the best choice for our application of large data. 
Vector is a dynamic array that, according to cplusplus, can efficiently change its size dynamically according
to the container. It can also efficiently insert and delete data at specific points in the array unlike forward_list
https://cplusplus.com/reference/vector/vector/

LIST COULD BE A GOOD CHOICE TOO CONSIDERING ITS MODIFIERS AND LIST OPERATIONS 
https://cplusplus.com/reference/stl/

I WILL USE VECTOR FOR NOW, BUT IF I HAVE COMPLICATIONS WITH SYNTAX, CODE, OR ALGORITHMS, I WILL SWITCH TO LIST

12/14/2024 -- Yeah.... I switched to list. lets continue
*/

class Package;                  // Forward Declaration - A apart of B, B apart of A 

class Customer {

private:
    std::string name; 
    int id; 
    std::list<Package*>packages;                 // This template idea was derived with lecture Templates - Lecture 1 @ 31:14 of 6_templates_class.cpp, & example 5_templates_vector_traversal.cpp
    std::list<Package*>::iterator it;           // Used iterator for the destructor and etc for traversal
public:                                           
    Customer() = default;                                 // Constructor EXPLAINED IN POLYMORPHISM LECTURE 2A
    ~Customer();                                         // Deconsturctor
    Customer(const std::string& name, int id);          // parameterized constructor with pass by reference 

    std::string getName() const;                         // Accessor function 
    int getID() const;                                  // Accessor function

    void setName(const std::string& newName);               // Mutator function
    void setID(int newID);                                 // Mutator function 

    friend std::ostream& operator<<(std::ostream &os, const Customer& customer);   // Overload to output data to console    // Overload concept with the direction of Project 2 by just replacing Store with Customer
    friend std::ostream& operator<<(std::ostream &os, const std::list<Customer*> &customer);   
    friend bool operator==(const Customer& o1,const Customer& o2);                 // Overload customer to determine if two objects are equivalent 
    friend bool operator==(const std::list<Customer*>& o1,const std::list<Customer*> & o2); 


    
// Container member functions 
    //void display(std::vector<Package*> &vec) const;               // WILL WORK OFF TEMPLATE PRINTING AS DESCRIBED IN TEMPLATE LECTURE 

};

#endif
