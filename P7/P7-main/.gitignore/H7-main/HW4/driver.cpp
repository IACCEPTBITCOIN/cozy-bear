#include "IntArray.h"
#include <iostream>

int main(){
    std::cout << std::endl; 
   
    IntArray arr1;
    std::cout<< "Default Array Size: " << arr1.getSize() << std::endl;
    arr1.print();
    
    IntArray arr2(10);
    std::cout<< "Modified Array Size: " << arr2.getSize() << std::endl;
    
    std::cout<< "Value of Array1: " << arr1.getValue(2) << std::endl;


    std::cout<< "Value of Array2: " << arr2.getValue(2) << std::endl;

    std::cout << "Replaced Array:" << std::endl;
    for(int i =0; i<arr2.getSize(); ++i){
        arr2.replace(i, i+1);
    }

    arr2.print();

    arr2.swap(2,4);
    std::cout << "After Swapping" << "\n";

    arr2.print();


    std::cout << std::endl; 
    return 0; 
}