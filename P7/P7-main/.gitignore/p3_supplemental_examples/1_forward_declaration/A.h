#ifndef A_H
#define A_H

#include "B.h"  // include class B

class B;        // forward declare class B

class A {
    B var;      // A is able to store variables or containers of type B
};

#endif
