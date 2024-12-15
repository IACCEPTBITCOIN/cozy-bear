#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>

class Square {

private: 
    int side;
    
public:

    Square();
    Square(int s);

    int getSide();
    
    void setSide(int s);
    
    int area(); 
      
};
void print(Square &S);

#endif