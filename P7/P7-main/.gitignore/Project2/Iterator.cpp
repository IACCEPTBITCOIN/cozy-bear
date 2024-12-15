#include "Iterator.h"
#include "Node.h"

    Iterator::Iterator(Node *n): current(n) {}          // point iterator to specific node

    void Iterator::next() {current = current->next;}                   // advance iterator to next node
        
    void Iterator::prev() {current = current->prev;}                  // advance iterator to previous node

    
    bool Iterator::hasNext() const // return true if current is a valid node (not nullptr), false otherwise
    {                   
        if(current != nullptr) { 
            return true; 
        } else {
            return false;
        }
    }
    
    bool Iterator::hasPrev() const          // return true if current is a valid node (not nullptr), false otherwise
    {               
        if(current != nullptr) { 
            return true; 
        } else {
            return false;
        }
    }   
     
    Store& Iterator::getData()            // return a reference to the data stored in the current node
    {          
        return current->data;
    }
