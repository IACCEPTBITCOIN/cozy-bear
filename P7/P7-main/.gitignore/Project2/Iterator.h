#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include "Node.h"

struct Iterator{

private:
    Node *current; 
public: 
    friend class List;  // PART 5 PHASE 1 - MICHAEL FROM EXAMPLES OF PSUEDO CODE --MICHAEL
    Iterator();
    Iterator(Node *n);
    void next();
    void prev();
    bool hasNext() const;
    bool hasPrev() const;
    Store& getData();     // int& was updated to Store& to accept complex data type --MICHAEL
};

#endif