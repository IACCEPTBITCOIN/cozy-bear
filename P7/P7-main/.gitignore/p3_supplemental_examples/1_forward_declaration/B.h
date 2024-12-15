#ifndef B_H
#define B_H

#include "A.h"  // include class A

class A;        // forward declare class A

class B {
    A var;      // B is able to store variables or containers of type A
};

#endif
