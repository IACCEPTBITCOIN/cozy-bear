#include "square.h"

Square::Square(): side(1){}
Square::Square(int s) : side(s){}

int Square::getSide(){return side;}

void Square::setSide(int s){side = s;}

int Square::area(){return side * side;}

void print(Square &S){
    std::cout << " Area of Square : " << S.area() << std::endl;
    }
