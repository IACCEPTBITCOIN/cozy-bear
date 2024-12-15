#ifndef NODE_H
#define NODE_H

#include <iostream> 
#include "Store.h"

struct Node {
    
    private:
    Store data;                   // Data stored in the node   --BUG, int data had to be Store data
    Node *next;                // Pointer to the next node
    Node *prev;               // Pointer to the previous node

    public:
    friend class List;              // PART 5 PHASE 1 ******** -MICHAEL FROM EXAMPLES OF PSUEDO CODE
    friend class Iterator;  
    Node();                     //DEFAULT CONSTRUCTOR
    Node(const Store &d);           //PARAMETERIZED CONSTRUCTOR
        // DOUBLY LINKED LIST AND ITERATOR 2_DOUBLY_LINKED_LIST_ITERATOR.CPP
};

#endif