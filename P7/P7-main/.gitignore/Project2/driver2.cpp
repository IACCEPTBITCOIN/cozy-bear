#include "Iterator.h"
#include "List.h"
#include "Node.h"
#include "Store.h"
#include <fstream> 
#include <iostream> 
#include <sstream>
 
class FileRead {
public: 
    void read(const std::string& filename, List& lists);
    //void write(List& lists); 
};

void FileRead::read(const std::string& filename, List& lists){
std::ifstream file(filename);

if (!file.is_open()) {
    std:: cerr << "Error: " << filename << " does not exist" << std::endl;    // finished with the help of 1_exceptions.cpp and 
    return;                                                         // https://cplusplus.com/doc/tutorial/files/
}
std::string line;                           // declare line so it can be called in the while loop.

while(std::getline(file, line) ) {   // read line of text from file into the variable line.             
    std::stringstream ss(line);                                             
    std::string name;
    int employees; 

    std::getline(ss, name, ','); // IT WASNT RUNNING BECAUSE OF "," instead of ','
    ss >> employees; 

    lists.push_back(Store(name, employees));
}

    file.close();                           // must always close so it the file doesn't lock or corrupt 
}
/*
void FileRead::write(List &lists)
{
    for (Iterator it = lists.begin(); it != lists.end(); ++it) {
        Store s = *it;
        file << s.getName() << "," << s.getEmployees() << "\n";
    }
    file.close();               // NOT NEEDED BUT WAS FUN TO EXPERIMENT WITH
}
*/

int main() {
    
    std::cout << std::endl; 

    List list;
    List l2; 

    std::cout << "-----PUSH FRONT/BACK-----\n";           // test push front/back
    list.push_front(Store("Apple", 400));
    list.push_front(Store("Tesla", 600)); 
    list.push_back(Store("Walmart", 872));  
    list.push_back(Store("Target", 1002)); 
    list.push_back(Store("Lidl", 1202)); 
    std::cout << "LIST 1\n"; 
    list.print(); 
    std::cout << "LIST 2\n"; 
    l2.push_front(Store("Bytedance", 10));
    l2.push_front(Store("Temu", 20));
    l2.push_back(Store("AliExpress", 30)); 
    l2.push_back(Store("Shein", 40));
    l2.push_back(Store("Alibaba", 50));
    l2.print();
    std::cout << "Reverse\n";
    l2.printRev();
    
    
    Iterator it = list.begin();                 // point an iterator to the start of the list
    
    std::cout << "\nFRONT/BACK LIST 1\n";              // test front/back
    std::cout << list.front() << "\n";       
    std::cout << list.back() << "\n";
    std::cout << "List 1: \n";
    list.print();   

    std::cout << "\nFIND/INSERT\n";             // test find and insert 
    it = list.find(Store("Target", 1002));
    std::cout <<  it.getData() << "\n";          // test return value

    it = list.find(Store("Walmart", 872));
    std::cout <<  it.getData() << "\n";          // test return value 
    std::cout << "\nINSERT Best Buy & 100 Employees\n";   
    it = list.insert(it, Store("Best Buy", 100));                // I BELIEVE THERE WAS A TYPO WITH BACK INSTEAD OF INSERT
    std::cout << "Returned Iterator: " 
              << it.getData() << "\n";          // test return value

    it = list.find(Store("Lidl", 1202));                // I finally got the find function to run by adding the class store to read strings & integers
    std::cout <<  it.getData() << "\n";    
    it = list.insert(it, Store("Micro Center", 220));                    
    list.print();
    list.printRev();  

    Iterator i = l2.begin();

    std::cout << "\nFRONT/BACK LIST 2\n";              // test front/back
    std::cout << "FRONT: ";
    std::cout << l2.front() << "\n"; 
    std::cout << "BACK: ";      
    std::cout << l2.back() << "\n";
    std::cout << "List 2: \n";
    l2.print();

    std::cout << "\nFIND/INSERT\n";             // test find and insert 
    i = l2.find(Store("Temu", 20));
    std::cout <<  i.getData() << "\n";          // test return value
    i = l2.find(Store("AliExpress", 30));
    std::cout <<  i.getData() << "\n";          // test return value 

    std::cout << "\nINSERT BYD & 10000 Employees\n";   // INSERT BYD BEFORE ALIEXPRESS
    i = l2.insert(i, Store("BYD", 10000));                   
    std::cout << "Returned Iterator: " 
              << i.getData() << "\n";          // test return value

    i = l2.find(Store("Alibaba", 50));
    std::cout <<  i.getData() << "\n";  
    std::cout << "\nINSERT MSS & 22000 Employees\n";   //INSERT MSS BEFORE ALIBABA
    i = l2.insert(i, Store("MSS", 22000));
    std::cout << "Returned Iterator: " 
              << i.getData() << "\n";          // test return value
                                
    l2.print();
    l2.printRev();  

    list.print();
    std::cout << "\nFIND/ERASE\n";              // test erase and insert 
    it = list.find(Store("Apple", 400));
    std::cout << "Erase Apple & return next " << "\n";        
    it = list.erase(it);                       // erase "Apple" 
    std::cout << "Returned Iterator: " 
              << it.getData() << "\n";          // test return value which is next value in the list "Best Buy"
    it = list.find(Store("Best Buy", 100));   
    it = list.erase(it);                       // erase 300 (middle case)  
    it = list.find(Store("Walmart", 872));   
    it = list.erase(it);                       // erase 800 (edge case)  

    list.print();

    i = l2.find(Store("Temu", 20));
    std::cout << "Erase Temu & return next " << "\n";        
    i = l2.erase(i);                       
    std::cout << "Returned Iterator: " 
              << i.getData() << "\n";          // test return value which is next value in the list "Bytedance"
    i = l2.find(Store("Bytedance", 10));   
    i = l2.erase(i);                        
    i = l2.find(Store("BYD", 10000));   
    i = l2.erase(i);                       
    std::cout << "---- Removal of Temu, Bytedance, & BYD -----\n";
    l2.print();
    std::cout << "---- Removal of Apple, Best Buy, & Walmart -----\n";
    list.print();
    list.printRev();   

    std::cout << "COPY\n";                     // test duplicate   
    List list2;
    list.duplicate(list2);                 // duplicate list without sharing memory
    std::cout << "-----List----- " << std::endl;
    list.print(); 
    std::cout << "-----Copy----- " << std::endl; 
    list2.print();                   // test if the copy contains the original data to check for distinct memory allocation                    
    std::cout<<std::endl;

    std::cout << "COPY\n";                     // test duplicate   
    List list3;
    l2.duplicate(list3);                 // duplicate list without sharing memory
    std::cout << "-----List 2 ----- " << std::endl;
    l2.print(); 
    std::cout << "-----Copy 2----- " << std::endl; 
    list3.print();                   // test if the copy contains the original data to check for distinct memory allocation                    
    std::cout<<std::endl;

    
    std::cout << "\n----POP FRONT/BACK----\n";          // test pop front/back
    std::cout << "\nList 1\n";   
    list.pop_front();
    list.pop_back();
    list.print();
    std::cout << "\nReverse: \n"; 
    list.printRev(); 
    std::cout << "\nList 2\n"; 
    l2.pop_front();
    l2.pop_back();
    l2.print();
    std::cout << "\nReverse: \n"; 
    l2.printRev();
    
// I feel like this is where I went wrong by not being able to continue the testing of Phase 2 functions with the data above

std::cout<< " Phase 2 Functions "<< std::endl;
std::cout<< "-------------------" << std::endl;

Store p1, p2;           // inititalized with no company names and 0 employees
List f1;
List f2; 
p1.print();
std::cout<< "List 1 "<< std::endl;
p1.setEmployees(55); 
p1.setName("State Farm");
p1.print();
std::cout<< "List 2 "<< std::endl;
p2.setEmployees(22); 
p2.setName("Metlife");
p2.print();

Store p3("Liberty", 3000);              //Directly invoke a Store containter. 
std::cout<< "List 3 "<< std::endl;
p3.print();

std::cout<< "\nCompare Function: "<< std::endl;

if(compare(p1,p2,false)){
    std::cout << "\nList 1 has more employees than List 2\n";
    }else{
    std::cout << "\nList 1 has fewer employees than List 2\n";
}
std::cout<<std::endl;
p1.setEmployees(22);
p2.setEmployees(55);
p1.print();
p2.print();

std::cout<< "\nFLIP p1 and p2 values" << std::endl;
if(compare(p1,p2,false)){
    std::cout << "\nList 1 has more employees than List 2";   //Overloading can be done  
    }else{
    std::cout << "\nList 1 has fewer employees than List 2";
}



std::cout << std::endl; 
std::cout<< "\nEquivalence Function: "<< std::endl;
p1.print();
p2.print();
std::cout << (p1 == p2) << "\t p1 != p2" << std::endl;
Store p4("Liberty", 3000); 
p3.print();
p4.print();
std::cout << (p3 == p4) << "\t P3 == P4" << std::endl;
p4.setName("General");
p3.print();
p4.print();
std::cout << (p3 == p4) << "\t P3 != P4" << std::endl;

List g2;
Store data; 
FileRead fileReader;
fileReader.read("data.csv", g2);
std::cout<< "\nContents from data.csv: "<< std::endl;
g2.print();


std::cout<< "\n TESTING EDGE CASES "<< std::endl;

Store empty;
List empty2; 

std::cout<< "\nTest single elements of a list "<< std::endl;
std::cout<< "---------- Phase 1 ------------ "<< std::endl;
empty2.push_back(Store("Single", 1));
std::cout << "Single List: \n";
empty2.print();
try {
    empty2.pop_front();
    empty2.pop_back();
} catch (std::exception& e) {
    std::cout << "Caught exception on pop from empty list: " << e.what() << std::endl;
}
std::cout << "Printing empty Store container of List\n";
empty.print();

try {
    empty2.front();
} catch (std::exception& e) {
    std::cout << "Caught exception on front of single-element list: " << e.what() << std::endl;
}

try {
    empty2.back();
} catch (std::exception& e) {
    std::cout << "Caught exception on back of single-element list: " << e.what() << std::endl;
}

List largeList;
for (int i = 0; i < 100; ++i) {
    largeList.push_back(Store("Company" + std::to_string(i), i * 5));
}

std::cout << std::endl; 
std::cout << "Large list print:" << std::endl;
largeList.print();

std::cout << "Testing Duplcates:" << std::endl;
List duplicateList;
duplicateList.push_back(Store("Duplicate", 10));
duplicateList.push_back(Store("Duplicate", 10));
duplicateList.push_back(Store("Unique", 20));
duplicateList.print();
std::cout << std::endl; 
Iterator it2 = duplicateList.find(Store("Duplicate", 10));
duplicateList.erase(it2);
duplicateList.print();

// EDGE CASE REVEALS IT DOES NOT REMOVE TWO SETS OF DATA IF THEY ARE THE SAME, 
// THEY ARE CONSIDERED SEPERATE POSITIONS IN MEMORY
std::cout << "Edge case of Fileread(): \n";

FileRead fileHandler;
List null; 

fileHandler.read("bob.csv", null);
fileHandler.read("bob2.csv", null);
fileHandler.read("bob3.csv", null);

std::cout << "\nIterator edge cases: " << std::endl;
std::cout << std::endl;
/*
List testit;
testit.push_back(Store("Invalid", 1));

Iterator nullIT = testit.end();
try {
    ++nullIT;  // TEST TO INCREMENT BEYOND THE END OF FUNCTION, CANT GET TO WORK BECAUSE ITERATOR DOESN"T HAVE ACCESS TO operator++ OVERLOAD
    testit.erase(nullIT);
} catch (std::exception& e) {
    std::cout << "Caught exception with invalid iterator: " << e.what() << std::endl;
}
*/
std::cout << "Equivalence & Compare tests " << std::endl;
std::cout << "---------------------------" << std::endl;
Store uninit1, uninit2;
if (compare(uninit1, uninit2, false)) {
    std::cout << "Compare works with uninitialized stores." << std::endl;
} else {
    std::cout << "Compare failed with uninitialized stores." << std::endl;
}
std::cout << std::endl;

std::cout << (uninit1 == uninit2) << " - Uninitialized stores are equivalent." << std::endl;

std::cout << std::endl; 
return 0; 

}
