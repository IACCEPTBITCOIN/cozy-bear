
#include "Files.h"
#include "Container.h"
#include <iostream>

int main(){
    std::cout << std::endl; 
    
    intArray a1;                          // initialize intArray
    FileRead r1;                          // Initialize the read function 
    r1.read(a1);                          //  initialize r1 to read variable a1

    std::cout << "data.csv contents: " << std::endl;      
    a1.print();                                       // a1 is read and then printed to the console 

    std::cout << std::endl;
    std::cout << "Size of array : " << a1.size() << std::endl; 
    std::cout << "Capacity of array : " << a1.maxSize() << std::endl; 

    a1.push_back(11); 
    std::cout << std::endl;
    a1.print(); 

    std::cout << "RESERVE FUNCTION INITIALIZES once numValues > maxValues" << std::endl; 
    std::cout << "Capacity * 2\n" << std::endl; 
    std::cout << "Capacity of array : " << a1.maxSize() << std::endl; 

    a1.push_back(12);
    std::cout << std::endl;
    a1.print(); 

    std::cout << std::endl;
    std::cout << "Size of array : " << a1.size() << std::endl; 
    std::cout << "Capacity of array : " << a1.maxSize() << std::endl; 

    std::cout << std::endl;

    a1.push_back(13); 
    a1.push_back(14); 
    a1.push_back(15);
    a1.print(); 
    a1.push_back(16); 
    a1.push_back(17); 
    a1.push_back(18); 
    a1.push_back(19);
    a1.push_back(20); 
    a1.push_back(21);
    a1.print();

    std::cout << std::endl;
    std::cout << "Size of array : " << a1.size() << std::endl; 
    std::cout << "Capacity of array : " << a1.maxSize() << std::endl; 

    // The RESERVER function is working in the backend to extend the array once size > capacity
     
    a1.clear(); 
    a1.print();
    std::cout << "\nEmpty array? (0 no, 1 yes) = " << a1.empty() << std::endl; 

    /*Cant figure out how to get the array to reinitialize with default values - Michael*/


    std::cout << std::endl; 
    return 0; 
}
 