#include <iostream>
#include "square.h"
#include "rectangle.h"
#include "triangle.h"

int main(){
    std::cout << std::endl; 
    
    Square s1;
    print(s1);

    Square s2(6);
    print(s2);

    s2.setSide(4);

    Rectangle r1;
    print(r1);
    
    Rectangle r2(3,5);
    print(r2);

    r2.setWidth(3);
    r2.setLength(4);

    Triangle t1;
    print(t1);
    
    Triangle t2(3,5);
    print(t2);

    t2.setWidth(3);
    t2.setHeight(4);

    std::cout << std::endl; 
    return 0; 
}

