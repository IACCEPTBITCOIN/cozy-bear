#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include "Container.h"
#include <cassert>

// Declares the function 'commonValues' that takes two 'intArray' references (A and B) and returns a pointer to an 'intArray'. 
intArray* commonValues(intArray& A, intArray& B);
bool isPartOf(intArray& A, intArray& B);
    

#endif