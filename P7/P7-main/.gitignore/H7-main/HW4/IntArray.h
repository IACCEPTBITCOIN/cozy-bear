#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>
#include <cassert>

class IntArray {

    private: 
        int* arr;
        int size;
    public:
        IntArray();
        IntArray(int s);
        ~IntArray();
        int getSize() const;
        int getValue(int index) const;

        void replace(int index, int value);
        void swap(int index_1, int index_2);
        void print() const;
        
};

#endif