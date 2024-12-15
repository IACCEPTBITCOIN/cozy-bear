#include "Package.h"
#include "Customer.h"

/*
CORE AND DATA MEMBERS IMPLEMENTATION HAVE BEEN ADDED FOR PACKAGE BY MICHAEL BYRD
*/

//Package::Package() : name(""), id(0), maxPackages(0){}    // Default Constructor COMMENTED OUT SINCE PACKAGE = DEFAULT; defines the constructor in the header file with all data members 

Package::~Package()
{
    for(it = customers.begin(); it != customers.end(); ) {    
        delete *it;                                // Destructor to avoid memory leak  GOING OFF LOOP BELOW AS SAID IN 1:05:15 of "Templates - Lecture 1"  //MICHAEL    
        it = customers.erase(it);                   // CAN ALSO BE USED FOR INSERT // MUST MAKE SURE ITERATOR POINTS TO LEGITIMATE NODE                                                                                                             
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

// Prof talked about auto, It can be used to identify a type of package such as int, string, double, etc and account for any type instead of automatically declaring variable type
 WILL EXPERIMENT ONCE PHASE 1 IS COMPLETE 
for(auto box : packages){delete box;}
packages.erase();   

*/

Package::Package(const std::string &name, int id, int maxPackages) : name(name), id(id), maxPackages(maxPackages) {}    // Paramaterized Constructor  // MICHAEL

int Package::getID() const                             
{
    return id;                              // Accessor function //MICHAEL
}

std::string Package::getName() const 
{
    return name;                                    // Accessor function // MICHAEL
}

int Package::getMaxPackages() const 
{
    return maxPackages;                                    // Accessor function // MICHAEL
}

void Package::setID(int id)
{
    this -> id = id;                            // Mutator function // MICHAEL
}

void Package::setName(const std::string& name)
{
    this -> name = name;                            //  Mutator function // MICHAEL
}

void Package::setMaxPackages(int maxPackages)
{
    this -> maxPackages = maxPackages;                            //  Mutator function // MICHAEL
}

std::ostream &operator<<(std::ostream &os, const Package& pkg)
{
    os << "Package Name: " << pkg.name                        // Needed to access string outputs to the console.  // MICHAEL
    << ", Package ID: " << pkg.id <<"\n";                             
    return os;
}

bool operator==(const Package& p1, const Package& p2)
{
    if( p1.name != p2.name || p1.id != p2.id ){          // if packages p1 does not equal p2
        return false;                                     // SINCE LIST DOES NOT SUPPORT RANDOM ACCESS UNLIKE VECTOR, WE MUST USE ITERATORS TO COMPARE ELEMENTS IN SEQUENTIALLY IN THE LIST
    }
    if(p1.customers.size() != p2.customers.size()){
        return false; 
    } 
    auto it1 = p1.customers.begin(); 
    auto it2 = p2.customers.begin();

    while(it1 != p1.customers.end() && it2 != p2.customers.end()){  
        if(!(**it1 == **it2)){
            return false; 
        }
        ++it1;
        ++it2;
    }
    return true;                                                                   
}

 