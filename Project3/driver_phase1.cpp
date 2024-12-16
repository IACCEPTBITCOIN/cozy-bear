#include <iostream>
#include "Customer.h"
#include "CustomerUI.h"
#include "Files.h"
#include "Package.h"
#include "UPS.h"
#include "UPSUI.h"


int main() {

    std::cout << std::endl; 
    std::cout << "\U0001F44D" << std::endl;
    std::cout << std::endl;

    std::list<Customer*> list;                             // -- Instantiate Customer object pointers
    std::list<Customer*>::iterator it;                     //  iterator for a dynamic array

    std::list<Package*> truck;                          // Instantiate Package object pointers
    std::list<Package*>::iterator it2; 
    
    truck.push_back(new Package("Beauty Blender", 2093, 17));
    truck.push_back(new Package("2010 Volkswagen EOS Ignition Cylinder", 22, 5));                   // Directly invoke objects to Package container
    truck.push_back(new Package("iPhone 13 Dual-Sim Conversion Kit", 1876, 200));
    truck.push_back(new Package("2010 Volkswagen Taos Auto-Transmission Torque Converter", 19023, 1));

    std::cout << "Package Invoked Objects" << std::endl; 
    std::cout << "-----------------------" << std::endl;

    for(Package* it2 : truck) 
    {                                           // ranged for loop to read the list using an iterator (simple syntax relative to normal for loop
        std::cout << *it2;                       // p points to value pointed to by the loop iterator                              
    }                                         // Derived from template list traversal ex 6
    std::cout << "\n";

    truck.clear(); 
    std::cout << truck << std::endl;  // Prints nothing due to deletion of object from memory

    std::cout << "Read from Package.csv" << std::endl;
    std::cout << "----------------------" << std::endl;

    readPackages(truck); 
    std::cout << truck << std::endl; 

    truck.clear(); 

    list.push_back(new Customer("Bob Marley", 2) );              
    list.push_back(new Customer("Austin Powers", 3) );          // Directly invoke objects to Customer container
    list.push_back(new Customer("Jason Bourne", 4) );
    list.push_back(new Customer("Kim Il-Sung", 5) );
    list.push_back(new Customer("Abraham Lincoln", 6) );

    std::cout << "Customer Invoked Objects" << std::endl; 
    std::cout << "------------------------" << std::endl; 

    for(Customer* it : list) 
    {                                           // ranged for loop to read the list using an iterator (simple syntax relative to normal for loop
        std::cout << *it;                       // p points to value pointed to by the loop iterator                              
    }                                         // Derived from template list traversal ex 6
    std::cout << "\n";

    list.clear();

    std::cout << std::endl;
    std::cout << "Read from Customer.csv" << std::endl;
    std::cout << "----------------------" << std::endl;

    readCustomers(list);                     // Reading of customer.csv 
    std::cout << list << std::endl;         // Overload to print customer objects 
    list.clear();

    std::cout << std::endl;
    std::cout << "Test Equivalence of Customer Objects" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    std::list<Customer*> list1;                             
    
    list1.push_back(new Customer("Baba Yaga", 3));              // store pointers to dynamic objects // Directly invoke the Customer class

    std::list<Customer*> list2;                            
    
    list2.push_back(new Customer("Baba Yaga", 3) );            
    
    
    std::cout << (list1) << std::endl; 
    std::cout << (list2) << std::endl; 
    std::cout << (list1 == list2) << std::endl; 
    list1.clear();
    list2.clear(); 

    std::cout << std::endl; 
    list1.push_back(new Customer("Shohei Ohtani", 3));  
    list2.push_back(new Customer("Juan Soto", 2)); 
    std::cout << (list1) << std::endl; 
    std::cout << (list2) << std::endl; 
    std::cout << (list1 == list2) << std::endl; 

    std::cout << std::endl;
    std::cout << "Test Equivalence of Package Objects" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    std::list<Package*> box1;                             
    
    box1.push_back(new Package("Test Package", 3, 22));              // store pointers to dynamic objects // Directly invoke the Customer class

    std::list<Package*> box2;                            
    
    box2.push_back(new Package("Test Package", 3, 22) );            
    
    std::cout << (box1) << std::endl; 
    std::cout << (box2) << std::endl; 
    std::cout << (box1 == box2) << std::endl; 

    box1.clear();
    box2.clear(); 

    std::cout << std::endl; 
    box1.push_back(new Package("McDouble", 3, 2));  
    box2.push_back(new Package("Happy Meal", 2, 3)); 
    std::cout << (box1) << std::endl; 
    std::cout << (box2) << std::endl; 
    std::cout << (box1 == box2) << std::endl; 


    std::cout << std::endl; 
    std::cout << "Testing of Print() Function" << std::endl; 
    std::cout << "----------------------------" << std::endl; 

    std::cout << "Package 1" << std::endl; 
    print(box1); 
    
    std::cout << "Package 2" << std::endl; 
    print(box2); 

    std::cout << "Customer 1" << std::endl; 
    print(list1); 
    
    std::cout << "Customer 2" << std::endl; 
    print(list2); 
    
    box1.clear(); 
    list1.clear(); 
    readCustomers(list1);
    readPackages(box1);

    std::cout << "Package.csv" << std::endl; 
    std::cout << "-----------" << std::endl;
    print(box1);  

    std::cout << "Customer.csv" << std::endl; 
    std::cout << "------------" << std::endl; 
    print(list1);  

    std::cout << "\U0001F44D" << std::endl;
    
    box1.clear(); 
    box2.clear();
    list1.clear(); 
    list2.clear(); 
    truck.clear(); 
    
    std::cout << std::endl; 
    return 0;

}