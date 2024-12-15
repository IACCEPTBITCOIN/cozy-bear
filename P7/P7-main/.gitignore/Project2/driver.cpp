#include "Iterator.h"
#include "List.h"
#include "Node.h"
#include "Store.h"
#include <iostream> 

int main() {
    
    std::cout << std::endl; 

    List list; 

    std::cout << "PUSH FRONT/BACK\n";           // test push front/back
    list.push_front(400);
    list.push_front(200);  
    list.push_front(100);
    list.push_back(600);  
    list.push_back(800); 
    list.push_back(1000);
    list.push_back(1200); 

    list.print();                                // test forward and reverse traversal
    list.printRev();

    std::cout << "\nPOP FRONT/BACK\n";          // test pop front/back
    list.pop_front();
    list.pop_back();
    list.pop_back();
    list.print();
    list.printRev(); 

    Iterator it = list.begin();                 // point an iterator to the start of the list

    std::cout << "\nFRONT/BACK\n";              // test front/back
    std::cout << list.front() << "\n";       
    std::cout << list.back() << "\n";
    list.print();   

    std::cout << "\nFIND/INSERT\n";             // test find and insert 
    it = list.find(200);
    std::cout << "Insert 100 before " 
              << it.getData() << "\n";          // test return value    
    it = list.insert(it, 100);                  // insert 100 before 200 (edge case) // I BELIEVE THER WAS A TYPO WITH BACK INSTEAD OF INSERT
    std::cout << "Returned Iterator: " 
              << it.getData() << "\n";          // test return value
    it = list.find(400);   
    it = list.insert(it, 300);                 // insert 300 before 400  (middle case)    
    list.print();
    list.printRev();    

    std::cout << "\nFIND/ERASE\n";              // test erase and insert 
    it = list.find(100);
    std::cout << "Erase 100 " << "\n";        
    it = list.erase(it);                       // erase 100 (edge case)
    std::cout << "Returned Iterator: " 
              << it.getData() << "\n";          // test return value
    it = list.find(300);   
    it = list.erase(it);                       // erase 300 (middle case)  
    it = list.find(800);   
    it = list.erase(it);                       // erase 800 (edge case)  
    list.print();
    list.printRev();   

    std::cout << "\nCOPY\n";                    // test duplicate
    List list_copy;
    list_copy.duplicate(list);                 // duplicate list without sharing memory
    it = list.find(200);                       // erase a node to modify the original list
    list.erase(it);                              
    list.print();
    list_copy.print();                           // test if the copy contains the original data to check for distinct memory allocation                    

    std::cout << std::endl; 
    return 0; 
}