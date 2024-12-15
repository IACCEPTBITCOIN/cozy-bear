#include "Files.h"
#include "Container.h"
#include <iostream>

int main(){
std::cout << std::endl; 
    
intArray a1;                    // initialize intArray a1
    
std::cout << "Initial array a1 with constructor values " << std::endl;
std::cout << "----------------------------------------" << std::endl;
std::cout << "Size of array : " << a1.size() << std::endl; 
std::cout << "Capacity of array : " << a1.maxSize() << std::endl; 
std::cout << std::endl;                  
FileRead r1;                          // Initialize the read function 
r1.read(a1);                          //  initialize r1 to read and fill a1 with the contents of the data.csv 
    
std::cout << "data.csv contents: " << std::endl;      
a1.print();                                      // a1 is read and then printed to the console 
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
a1.print();  
a1.push_back(19);
a1.push_back(20); 
a1.push_back(21);
a1.print();

std::cout << std::endl;
std::cout << "Size of array : " << a1.size() << std::endl; 
std::cout << "Capacity of array : " << a1.maxSize() << std::endl; 

std::cout << std::endl;
std::cout << "The RESERVE function works in the backend within push_back() to extend the array once size > capacity" << std::endl; 
std::cout << std::endl;

std::cout << "----------------" << std::endl;
std::cout << "Array is cleared " << std::endl;
std::cout << "----------------" << std::endl;

a1.clear(); 
std::cout << "\nEmpty array? (0 no, 1 yes) = " << a1.empty() << std::endl; 
std::cout << std::endl;

std::cout << "Array a1 reinitialized with default values: " << std::endl;                                     
std::cout << "Size of array : " << a1.size() << std::endl; 
std::cout << "Capacity of array : " << a1.maxSize() << std::endl; 

std::cout << std::endl;
r1.read(a1); 
std::cout << "Initilaize a1 again with data.csv:" << std::endl; 
a1.print();

std::cout << std::endl;
std::cout << "Frst Position [0] : " << a1.at(0) << std::endl;     // index is always maxValues - 1
std::cout << "Middle Position [4] : " << a1.at(4) << std::endl; 
std::cout << "Last Position [9] : " << a1.at(9) << std::endl; 
std::cout << std::endl;

std::cout << "Redefine all indexes to a different value: "<< std::endl; 
a1.print();
a1.at(9) = 10*10;
a1.at(8) = 9*9;
a1.at(7) = 8*8;
a1.at(6) = 7*7;
a1.at(5) = 6*6;
a1.at(4) = 5*5;
a1.at(3) = 4*4;
a1.at(2) = 3*3;
a1.at(1) = 2*2;
a1.at(0) = 1*1;
a1.print();

std::cout << std::endl;
std::cout << "First Position [0] : " << a1.at(0) << std::endl;     // index is always maxValues - 1
std::cout << "Middle Position [4] : " << a1.at(4) << std::endl; 
std::cout << "Last Position [9] : " << a1.at(9) << std::endl; 
std::cout << std::endl;

std::cout << "Remove last value from array with pop_back: " << std::endl;
a1.pop_back();
a1.print();

std::cout << std::endl;
std::cout << "Add removed value back to array with push_back: " << std::endl;
a1.push_back(100);
a1.print();
std::cout << "Size of array : " << a1.size() << std::endl; 
std::cout << "Capacity of array : " << a1.maxSize() << std::endl; 

std::cout << std::endl;
std::cout << "Add 5 to data with sortedInsert() in correct positon from small to large: " << std::endl; 
a1.sortedInsert(5);
a1.print();
std::cout << "Size of array : " << a1.size() << std::endl; 
std::cout << "Capacity of array : " << a1.maxSize() << std::endl; 
std::cout << std::endl;

std::cout << "Erase 5 that was added to position [2] with erase(): " << std::endl;  
std::cout << "Position [2] : " << a1.at(2) << std::endl; 
a1.print();
a1.erase(2);  
a1.print();

a1.resize(3); 
std::cout << std::endl;
std::cout << "Resize a1 to 3 values: " << std::endl; 
a1.print(); 
std::cout << "Size of array : " << a1.size() << std::endl; 
std::cout << "Capacity of array : " << a1.maxSize() << std::endl; 

std::cout << std::endl; 
std::cout << "Add 3 values to a1: " << std::endl; 
a1.sortedInsert(16);
a1.sortedInsert(25);
a1.push_back(36);

a1.print();
std::cout << "Size of array : " << a1.size() << std::endl; 
std::cout << "Capacity of array : " << a1.maxSize() << std::endl;

std::cout << std::endl; 
std::cout << "Accessing position [3] : " << a1.at(3) << std::endl; // if size is 3, index is [0,1,2]
a1.print();
std::cout << std::endl;

try 
{std::cout << "Accessing position [6]: " << a1.at(6) << std::endl;} 
catch (const std::out_of_range& e) 
{std::cout << e.what() << std::endl;}

std::cout << std::endl;
std::cout << "Trying to erase position [6]: " << std::endl;
a1.erase(6);
std::cout << std::endl;

std::cout << "Trying to erase position [7]: " << std::endl;
a1.erase(7);
std::cout << std::endl;

std::cout << "Erasing position [1]: " << std::endl;
a1.print();
a1.erase(1);
a1.print();
std::cout << "Size of array : " << a1.size() << std::endl; 
std::cout << "Capacity of array : " << a1.maxSize() << std::endl;
std::cout << std::endl;

// WE CAN POSSIBLY INCORPERATE TRY & CATCH BLOCK INTO AT() TO CLEAN UP THE DRIVER AS MUCH AS POSSIBLE
// WILL EXPLORE ONCE PHASE 3 IS CLOSE TO COMPLETION 
// FUNCTION IS STARTED BUT COMMENTED OUT IN CONTAINER.CPP
// -- MICHAEL


intArray a2;
std::cout << "Initialize array a2 with constructor values: " << std::endl;
std::cout << "-------------------------------------------" << std::endl;
std::cout << "Size of array : " << a2.size() << std::endl; 
std::cout << "Capacity of array : " << a2.maxSize() << std::endl; 
std::cout << std::endl;
                    
FileRead r2;
r2.read(a2);
std::cout << "data.csv to a2:" << std::endl; 
a2.print();
std::cout << std::endl;  

std::cout << "Resize a2 to 3 values: " << std::endl; 
// Resize to 3 and add values
a2.resize(3);
a2.print();
std::cout << std::endl; 
std::cout << "Adding values 10,20,30 to positions [0, 1, 2] : " << std::endl;
a2.at(0) = 10;
a2.at(1) = 20;
a2.at(2) = 30;
a2.print();
std::cout << std::endl; 
    
std::cout << "Front element: " << a2.at(0) << std::endl; // Should print 10
std::cout << "Middle element: " << a2.at(1) << std::endl; // Should print 20
std::cout << "Back element: " << a2.at(2) << std::endl; // Should print 30
std::cout << std::endl;

// Testing out-of-bounds access 
try {
std::cout << "Accessing out of bounds: " << a2.at(3) << std::endl; // Should throw an exception
} catch (const std::out_of_range& e) {
std::cout << e.what() << std::endl; // Should print "Index is out of bounds"
}

a2.resize(5); // Resize to 5 elements
a2.at(0) = 10;
a2.at(1) = 20;
a2.at(2) = 30;
a2.at(3) = 40;
a2.at(4) = 50;
std::cout << std::endl;
std::cout << "Before shrinking, size: " << a2.size() << std::endl;
a2.print();

// Shrinking the array
a2.resize(3); // Resize to 3 elements
std::cout << std::endl;

std::cout << "After shrinking, size: " << a2.size() << std::endl;
a2.print();
std::cout << std::endl;

std::cout << "Accessing the middle element after shrinking: " << a2.at(2) << std::endl; // Should print 30
  
// Attempting to access out-of-bounds elements
try {
std::cout << "Accessing element at index 4 after shrinking: " << a2.at(4) << std::endl;               
} catch (const std::out_of_range& e) {                                                        
std::cout << e.what() << std::endl; // Should print "Index is out of bounds"
}


// Growing the array
a2.resize(7); // Resize to 7 elements
std::cout << std::endl;
std::cout << "After growing, size: " << a2.size() << std::endl;
a2.print();

a2.resize(5); // Resize to 5 elements
a2.at(0) = 10;
a2.at(1) = 20;
a2.at(2) = 30;
a2.at(3) = 40;
a2.at(4) = 50;
std::cout << std::endl;
std::cout << "Before pop_back, size: " << a2.size() << std::endl;
a2.print();

// Pop the back element
a2.pop_back();
std::cout << std::endl;
std::cout << "After one pop_back, size: " << a2.size() << std::endl;
a2.print(); // Should print only 4 elements

// Continue popping elements
a2.pop_back();
a2.pop_back();
std::cout << std::endl;
std::cout << "After multiple pop_back calls, size: " << a2.size() << std::endl;
a2.print(); // Should print only 2 elements

// Test popping until array is empty
a2.pop_back();
a2.pop_back();
std::cout << std::endl;
std::cout << "After popping all elements, size: " << a2.size() << std::endl;
    
std::cout << std::endl;

// Attempt to pop from an empty array
a2.pop_back(); // Should print "Array is empty."
    
std::cout << std::endl; 
return 0; 

}
