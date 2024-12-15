#include "Customer.h"
#include "Package.h"

/*
CORE MEMBERS HAVE BEEN ADDED FOR CUSTOMER BY MICHAEL BYRD
*/

//Customer::Customer() : name(""), id(0), packages(0){}   

Customer::~Customer()
{
    for(it = packages.begin(); it != packages.end(); ) {    
        delete *it;                                // Destructor to avoid memory leak  GOING OFF LOOP BELOW AS SAID IN 1:05:15 of "Templates - Lecture 1"  //MICHAEL    
        it = packages.erase(it);                   // CAN ALSO BE USED FOR INSERT // MAKE SURE ITERATOR POINTS TO LEGITIMATE NODE                                                                                                             
    }               
}

/*
for(it = v.begin(); it != v.end(); ) {         // for loop to erase the dynamic memory pointed to by the vector (this is tricky)
        delete *it;                           // delete will remove the object from the list
        it = v.erase(it);                    // erase will remove the stored pointer AND reset the iterator to point to the next value to erase (important)                                                                                                   
    }

for(it = packages.begin(); it != packages.end(); ) {    
        delete *it;                                    
        it = packages.erase(it);                                                                                                                      
    }

// Auto talked about in lecture from prof, It can be used to identify a type of package such as int, string, double, etc and account for any type instead of automatically declaring variable type
 WILL EXPERIMENT ONCE PHASE 1 IS COMPLETE 
for(auto box : packages){delete box;}
packages.erase();   

*/

Customer::Customer(const std::string &name, int id) : name(name), id(id), packages(packages) {}    // Paramaterized Constructor  // MICHAEL

int Customer::getID() const                             
{
    return id;                              // Accessor function //MICHAEL
}

std::string Customer::getName() const 
{
    return name;                                    // Accessor function // MICHAEL
}

void Customer::setID(int newID)
{
    this -> id = newID;                            // Mutator function // MICHAEL
}

void Customer::setName(const std::string& newName)
{
    this -> name = newName;                           //  Mutator function // MICHAEL
}

std::ostream &operator<<(std::ostream &os, const Customer&customer)
{
    os << "Customer Name: " << customer.name                        // Needed to access string outputs to the console.  // MICHAEL
    << ", Customer ID: " << customer.id <<"\n";                            
    return os;
}

bool operator==(const Customer& o1,const Customer& o2) 
{
    if( o1.name != o2.name || o1.id != o2.id ){  
        return false;                                     // SINCE LIST DOES NOT SUPPORT RANDOM ACCESS UNLIKE VECTOR, WE MUST USE ITERATORS TO COMPARE ELEMENTS IN SEQUENTIALLY IN THE LIST
    }
    if(o1.packages.size() != o2.packages.size()){
        return false; 
    } 
    auto it1 = o1.packages.begin(); 
    auto it2 = o2.packages.begin();

    while(it1 != o1.packages.end() && it2 != o2.packages.end()){  
        if(!(**it1 == **it2)){
            return false; 
        }
        ++it1;
        ++it2;
    }
    return true;                                                                   
}   


/*
bool operator==(const Store &o1, const Store&o2 ) {                  // equivalence function
    return o1.name == o2.name && o1.employees == o2.employees; // essentially, if o1.name == o2.name & o1. # employees = o2. # employees
}                                                           // return bool true(1) if conditions are met, if not false(0)   //MICAHEL 
                                                            // From "Operator Overloading - Lecture 2" 29:48
*/

/*    CONTAINER MEMBER OF CUSTOMER TO DISPLAY PACKAGES OF CUSTOMER, THE SYNTAX IS INCORRECT 

void Customer::display(std::vector<Package*> &vec) const{
    
    typename std::vector<Package*>::iterator it = vec.begin();     // typename keyword required to specify an iterator for a vector of type Package       
    while( it != vec.end() ) {                              // advance the iterator until the end of the vector
        std::cout << *it << " ";                            // overloaded * returns the current object accessed by the iterator
        ++it;                                               // overloaded ++ to advance the iterator forward
    }                                                       // Modified from 4_template_containers.cpp   WORKS OFF OVERLOAD << OF PACKAGE.H
    std::cout << "\n";
}
*/