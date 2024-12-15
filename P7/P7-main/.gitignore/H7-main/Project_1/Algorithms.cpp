#include "Algorithms.h"
// Includes the header file "Algorithms.h" which contains function declarations for 'intArray'.

intArray* commonValues(intArray& A, intArray& B){  // Defines a function named 'commonValues' that takes two 'intArray' references 'A' and 'B'. 
                                                // The function returns a pointer to a dynamically allocated 'intArray', which will contain the common values between A and B.
    intArray* C =  new intArray(); 
    // Dynamically allocates a new 'intArray' object on the heap to store common values, and assigns the pointer to 'C'.

    int I1 = 0; // Initializes an integer variable 'I1' to 0. This will be used as the index for array A.
    int I2 = 0;     // Initializes an integer variable 'I2' to 0. This will be used as the index for array B

    while (I1 < A.size() && I2 < B.size()){  // Enters a loop that runs as long as both 'I1' and 'I2' are within the bounds of their respective arrays (A and B).
        assert(I1 >= 0 && I1 < A.size());  // Asserts that 'I1' is a valid index for array A. This is a safety check to ensure no out-of-bounds access.
        assert(I2 >= 0 && I2 < B.size());  // Asserts that 'I2' is a valid index for array B.
        
        if(A.at(I1) == B.at(I2)){  // If the current elements of arrays A and B (at indices 'I1' and 'I2') are equal, the following block executes.
            (*C).push_back(A.at(I1));     // Appends the common value (A.at(I1)) to array C using the 'push_back' function.
            I1++;  // Increments 'I1' to move to the next element in array A.
            I2++;  // Increments 'I2' to move to the next element in array B.
        } else if (A.at(I1) > B.at(I2)){ // If the current element in array A is greater than the element in array B, this block executes.
            I2++;  // Increments 'I2' to move to the next element in array B, because B's element is smaller, so we want to try a larger one.
        } else { // If the element in array A is smaller than the element in array B, this block executes.
            I1++;   // Increments 'I1' to move to the next element in array A, because A's element is smaller, so we want to try a larger one.
        }
    }
    return C;
    // Returns the pointer to the dynamically allocated array C, which now contains all common elements between A and B.
}

bool isPartOf(intArray& A, intArray& B)
{

if(A.size() > B.size()){   // first step to check if A is greater than B, if true return false and exit 
    return false; 
}


// Then we must iterate through pointed array B to find the start of A in B
int index = -1; // initialize an index to track if A starts in B 

for (int i = 0; i <= B.size() - A.size(); ++i) {
    if (B.at(i) == A.at(0)) {  // if A matches an index/element in B, store i in index and continue. 
        index = i; 
        break; 
    }
}

if(index == -1){        // IF NO MATCHING INDEX IS FOUND, A is not part of B 
    return false; 
} 

for (int i = 0; i < A.size(); ++i){         //check if all values of A are a consecutive order subset of B
    if (A.at(i) != B.at(index + i)){       // compare values in A and the elements in B 
        return false;                     // return false if not and exit
    }
}

return true; // If loop completes all logic above, A is apart of B

}


















