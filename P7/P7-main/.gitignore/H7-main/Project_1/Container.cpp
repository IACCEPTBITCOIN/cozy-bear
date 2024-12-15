#include "Container.h"
#include <iostream> 

intArray::intArray():maxValues(5), numValues(0), data(new int[maxValues]){};  // constructor with default values  
        
intArray::~intArray()
{                                       // defines the destructor 
    delete [] data; 
}                                           

bool intArray::empty() const{           // returns a bool statement of true if *data is empty
    return numValues == 0;          // found in 2_partially_filled_array_basic_functions.cpp
}

int intArray::size() const{
    return numValues;                    // defining size() to return size of *data
}                                         // numValues is **size

int intArray::maxSize() const{
    return maxValues;                     // defining maxSize() to return the potential capaciy of *data
}                                         // maxValues is **capacity

void intArray::reserve(int n){
    if (n > maxValues) {                    //if n (defined by accessor function) is greater than max values 
        int* newData = new int[n];          // point newData to n to grow an array to newly defined value

        for (int i = 0; i < numValues; ++i){  // for i to numValues-1 values of data, newData = data from original array 
            newData[i] = data[i];
        }
        delete[] data;              // deletion of *data to then reallocate data with newData
        data = newData;             // ^
        maxValues = n;              // Capacity now equals n and reserve function is complete
    }
} 

void intArray::clear() {
    delete[] data;            // delete the dynamic array
    maxValues = 5;           // reset capacity to original value
    numValues = 0;            // resnumValuesto original value 
    data = new int[maxValues]; // reallocation of *data 

    for (int i = 0; i < maxValues; ++i) {
        data[i] = 0;                             
    }
}; 

void intArray::push_back(int value) {     //  03_powerpoint_dynamic_arrays.pdf
    if(numValues == maxValues){         // numValues= capacity
        reserve(maxValues * 2);         // Double the capacity of array 
    }
    data[numValues++] = value;     // add the new value to the end of the array by post-incrementing value aftnumValues       
}

void intArray::print() const{
    for(int i=0; i < numValues; ++i) {         // found in 2_partially_filled_array_basic_functions.cpp
    std::cout << data[i] << " ";       
}
    std::cout << "\n";
} 

int& intArray::at(int index){
    if(index >=0 && index < numValues){ // Checks the validity of the index
        return data[index]; // if valid, returns a specifed index by reference in the data of the aray
    }else{
       throw std::out_of_range("Index is out of bounds");  // An exception is thrown to indciate if the index is out of bounds 
    }

}


/*  AT FUNCTION WITH TRY,CATCH BLOCK INCORPERATED INTO ITSELF (CANT GET FUNCTION TO INITIALIZE)
int intArray::at(int index){
    try{
        if(index < 0 ||  index >= numValues){ 
            throw std::out_of_range("Index is out of bounds");
        }
        return data[index];
    }
    catch (const std::out_of_range& e){
        std::cout << e.what() << std::endl;
        return; 
    }
}
*/

void intArray::resize(int n){
    if(n < numValues){          // if n is less than num values shrink the array
        numValues = n;          // size of the array has shrunk, if n is less than numValues
    }else if(n > numValues){    // if n is greater than numValues, it will then check if n is greater than maxvalues
        if(n > maxValues){      // if n is greater than max values, it will allocate the array with more memory 
            int *newData = new int[n];  // New memory is allocated for n elements, which will create a new larger sized dynamic array
            for(int i = 0; i<numValues; ++i){ // Elements from the old array will be copied to the new array
                newData[i] = data[i];
            }
            delete[] data;                  // Memory is deallocated 
            data = newData;                // the data pointer is pointed to the new allocated memory of newData
            maxValues = n;              // maxValues is then updated to modify the capacity of the array
    }
        for (int i = numValues; i< n; ++i){ // Loops sets a new space to default values, if it is resized or not
            data[i] = 0;                    // With the loop, allows the data to have new slots updated with 0's.
        }
        numValues = n;  //size is updated to show the new total number of elements in the array
    }   
}

void intArray::pop_back(){
    if(numValues > 0){                                      // This checks if the array is not empty
        numValues--;                                        // If it is not empty the last value is removed
        }
        else
        {
            std::cout << "Array is empty." << std::endl;    // Prints an error if the memory is already empty
        }
    }

void intArray::sortedInsert(int value){

if (numValues == maxValues){reserve(maxValues * 2);}          // if statement to grow the array if necessary 
    
int INDEX = numValues;                        // initialize index to what would be the last position if a number is added to its size

for (int i = numValues -1;  i >= 0; --i){       // fixed logic error of ++i to --i to fix Segmentation fault(core dumped)
    if(value < data[i])                       // if added value is greater than current size 
    {                                          
        {data[i + 1] = data [i];             
        INDEX = i;                            // shift to the right and update INDEX
    }
    }
    else
    {
        break;
    }
}

    data[INDEX] = value;                    // insert value at current INDEX
    numValues ++;                           // increase size(numValues) by 1
}                  

void intArray::erase(int index)     
{      
    if (index < 0 || index >= numValues)                        
    {std::cerr << "Index is out of bounds" << std::endl; return;}           // if statement to check if index is out of bounds 
                                                                          
    if( numValues > 0 && index >= 0 && index < numValues) {         // if there is room and index is legal  //03_powerpoint_dynamic_arrays.pdf
        for(int i = index; i < numValues - 1 ; ++i) {         //shift left // didn't add the -1 shift to properly execute the left shift and also had int i = index + 1 so execution was logically worng   
            data[i] = data[i + 1];                                  //  copy current to previous
        }
        --numValues; 
    }
}
    