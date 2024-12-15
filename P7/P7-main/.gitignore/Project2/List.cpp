#include "List.h"

                                             
//Node *head;                                 // pointer to the first node     

//Node *tail;                                 // pointer to the last node

List::List(): head(nullptr), tail(nullptr) {}     // constructor: construct an empty List
    
List::~List()                                     // destructor: safe deletion of all nodes in the stack
{
    Node *n = head;                         // point n to the first node
    Node *backup = nullptr;
    while(n != nullptr) {                   // advance n through all nodes in the List
    backup = n;                         // point backup to node n
    n = n->next;                        // advance n to the next node
    delete backup;                      // delete the backup node
    }
}  
    
Iterator List::begin() const{return Iterator(head);}         // return an iterator pointing to the first node (for forward traversal)
    
 
Iterator List::end() {return Iterator(nullptr);}           // return an iterator to the value past the end of the List (nullptr)
    

Iterator List::rbegin() const {return Iterator(tail);}   // return an iterator pointing to the tail node (for reverse traversal)
     
                   
Iterator List::rend() {return Iterator(nullptr);}      // return an iterator to the value past the start of the List (nullptr)
    
     

// Return true if the List is empty, false otherwise
bool List::empty() const                           
{
    if(head == nullptr) {                      
        return true;
    } else {
        return false;
    }
}
// Return a reference to the data inside the first node

Store& List::front() {return head->data;}              // UPDATED FOR Complex Data Type --Michael

// Return a reference to the data inside the last node

Store&  List::back() {return tail->data;}           // UPDATED FOR Complex Data Type --Michael

// Add a node to the front of the List   
void List::push_front(const Store &d)               // UPDATED FOR Complex Data Type  --Michael
{
    Node *n = new Node(d);                      // point n to a new node 
    if( empty() ) {                         // if List is empty, make n the first and last node
        head = tail = n;
    } else {
        n->next = head;                    // link n forward to the first node:    n  -> first
        head->prev = n;                    // link first node back to n:           n <-> first
        head = n;                          // n becomes the new first node
    }
}
// Add a node to the back of the List 
void List::push_back(const Store &d)       // UPDATED FOR Complex Data Type - Michael                        
{
    if( empty() ) {                         // if List is empty: push_front and exit
        push_front(d);
        return;
}
    
Node *n = new Node(d);                      // point n to new node
n->prev = tail;                        // link n backwards to the last node:       last <- n
tail->next = n;                        // link last forward to n:                  last <-> n                     
tail = n;                              // n becomes the new last node
}
// Remove the first node in the List
void List::pop_front()                      
{
    if(empty()){                         // if List is empty, exit
    return; 
}

Node *n = head;                        // point n to the first node
head = head->next;                    // second node becomes the new first node

if(head == nullptr) {                // if List will be empty, reset tail
    tail = nullptr;
} else {
    head->prev = nullptr;              // if List will have data, link first node backwards to nullptr
}

delete n;                                   // delete the original first node 
}
// Remove the last node in the List
void List::pop_back()
{
if( empty() ) {                         // if List is empty, exit
    return;
}

Node *n = tail;                        // point n to the last node
tail = tail->prev;                // point tail to the second to last node

if(tail == nullptr) {                  // if List will be empty, reset head
    head = nullptr;
} else {                                    // if List will have data, link new tail forwards to nullptr
tail->next = nullptr;
}

delete n;                                   // remove the original last node
}
// Add a new node before a specified node in the List
// If successful, return an iterator to the new node, otherwise return the original iterator
Iterator List::insert(Iterator it, const Store &d)     // UPDATED FOR Complex Data Type - Michael
{   
if( empty() || it.current == nullptr ) {// if List is empty or iterator invalid, exit and return the original iterator       
    return it;                                
}
 
Node *n = new Node(d);                      // point n to a new node
n->next = it.current;                       // link n forwards to the node after iterator:        n  -> it
n->prev = it.current->prev;                 // link n backwards to iterator:                p <-  n  -> it
it.current->prev = n;                       // link iterator backwards to node n:           p <-  n <-> it

if(n->prev == nullptr) {                    // if n is first node, point head to n
    head = n;
} else {                                    // if n is not the first node,
    n->prev->next = n;                      // link previous node forward to n              p <-> n <-> t
}

return Iterator(n);                         // return a pointer to the newly inserted node
}
// Remove a specified node from the List
// If successful, return an iterator to the node after the erased node, if this is the end of List return an iterator to nullptr
// If unsuccesful, return the original iterator
Iterator List::erase(Iterator it)
{
    if( empty() || it.current == nullptr ) {
    return it;                              // if List is empty or iterator invalid, exit, return original iterator  
} else if( it.current == head) {       // if iterator points to the first node, pop_front, return new Iterator to new first node
    pop_front();
    return begin();
} else if( it.current == tail ) {      // if iterator points to last node, pop_back, return nullptr
    pop_back();
    return Iterator(nullptr);
}

    Node *n = it.current->next;                 // point n to node after iterator:                                  b <-> it <-> a
    it.current->prev->next = it.current->next;  // link node before iterator forwards to node after iterator:       b  -> a
    it.current->next->prev = it.current->prev;  // link node after iterator backwards to node before iterator:      b <-> a
    
    delete it.current;                          // remove the iterator node

    return Iterator(n);                         // return the node after the iterator node
}
// Print a List in forward order
void List::print() const                         // print the List
{
    Iterator itr = begin();             // point iterator to the first node   
    while( itr.hasNext() ) {                    // advance the iterator forwards through all nodes in List   
        std::cout << itr.getData() << "";      // print the data of the iterator node
        itr.next();                             // point the iterator to the next node
    }   
    std::cout << "\n";    
}
// Print a List in reverse order
void List::printRev() const                       // print the List
{
    Iterator itr = rbegin();               // point iterator to the last node   
    while( itr.hasPrev() ) {                    // advance the iterator backwards through all nodes in List   
        std::cout << itr.getData() << "";      // print the data of the iterator node
        itr.prev();                             // point the iterator to the previous node
    }   
    std::cout << "\n";    
}
// Copy one List to another List
void List::duplicate(List &b) const                // duplicate List a contents into List b
{
    Iterator itr = begin();                   // point iterator to the first node   
    while( itr.hasNext() ) {                    // advance the iterator through all nodes in List   
        b.push_back(itr.getData());            // copy the data of the iterator node from List A into List B
        itr.next();                             // point the iterator to the next node
    }   
}
// Determine if the value d is in the List. 
// If successful, return an iterator to the node that stores data equivalent to d
// if unsuccessful, return an interator pointing to nullptr
Iterator List::find(const Store &d)         // UPDATED TO STORE COMPLEX DATA TYPE AND ONLY WAY TO GET IT TO RUN --MICHAEL     
{
    Iterator itr = begin();                // point iterator to the first node   
    while( itr.hasNext() ) {                    // advance the iterator through all nodes in List  
        if( itr.getData().getName() == d.getName() && itr.getData().getEmployees() == d.getEmployees()) {          // if node n stores the equivalent of d, 
            return itr;                         // return an iterator to the node storing the equivalent of d
        }
        itr.next();                             // point iterator to the next node
    }   
    return Iterator(nullptr);                   // if data was not found, return iterator pointing to nullptr
}

