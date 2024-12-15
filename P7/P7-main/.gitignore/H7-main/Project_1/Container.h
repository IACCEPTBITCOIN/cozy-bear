#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include "Files.h"
#include <cassert>


class intArray{
    private:
        int maxValues;
        int numValues;
        int *data;
    public:
        intArray();
        intArray(int maxValues);   // had to remove = 5 because it created a multiple constructor error since its value was constructed in Container.cpp 
        ~intArray();               
        bool empty() const;              
        int size() const;
        int maxSize() const;
        void reserve(int n);            // changed to void since it is a backend function and does not return a value but modifies data
        void clear();               // changed to void clear() because it does not return a value but modifies data
        void push_back(int value);      // added parameter value & removed const since data is modified
        void print() const;
        int& at(int index);
        void resize(int n);
        void pop_back(); 
        void sortedInsert(int value); // void to return the list with the sorted insert function 
        void erase(int index); // void because we are not returning index, we are only erasing and continuing with our business. 

};


#endif