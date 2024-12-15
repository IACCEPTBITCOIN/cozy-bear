#include "IntArray.h"
#include <iostream>
#include <cassert>

IntArray::IntArray(){
    size = 5;
    arr = new int[size];  
}
IntArray::IntArray(int inputsize){
    size = inputsize;
    arr = new int[size];      

}

IntArray::~IntArray()
{
    delete[] arr;
} 

int IntArray::getSize() const {
    return size;
}

int IntArray::getValue(int index) const {
    assert(index >= 0 && index < size);
    return arr[index];
}

void IntArray::replace(int index, int value){
    assert(index >= 0 && index < size);
    arr[index] = value;

}

void IntArray::swap(int index_1, int index_2){
    assert(index_1 >= 0 && index_1 < size);
    assert(index_2 >= 0 && index_2 < size);
    int temp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = temp; 

}

void IntArray::print() const{
    for(int i = 0; i<size; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";

}
