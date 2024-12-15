#ifndef LIST_H
#define LIST_H

#include <iostream> 
#include "Node.h"
#include "Iterator.h"
#include "Store.h"              // Included for complex data types

class List {

private:                                     
    Node *head;                                      // pointer to the first node                                              
    Node *tail;                                     // pointer to the last node
public:
    List();                                       // constructor: construct an empty list
    ~List();                                     // destructor: safe deletion of all nodes in the stack
    Iterator begin() const;
    Iterator end();
    Iterator rbegin() const;                   
    Iterator rend();   
    bool empty() const;                        
    Store& front();                 // CDT conversion                           --------
    Store& back();                  // CDT conversion                                   |
    void push_front(const Store &d);        // updated to store compled data type (CDT) | --- MICHAEL
    void push_back(const Store &d);        // updated to store CDT    ------------------|              
    void pop_front();                      
    void pop_back();
    Iterator insert(Iterator it, const Store &d);  // updated from int &d to Store &d  -MICHAEL
    Iterator erase(Iterator it);
    void print() const;                       
    void printRev() const;                     
    void duplicate(List &b) const;                 
    Iterator find(const Store &d); // before I got up to FIND it was "Iterator find(Store &d)" My error was not allowing me to convert char "Apple" in Store
    //Iterator find(int employees);              // I had the idea to just add the getName and getEmployee functions to the find function itself and it was able to run 
};

#endif