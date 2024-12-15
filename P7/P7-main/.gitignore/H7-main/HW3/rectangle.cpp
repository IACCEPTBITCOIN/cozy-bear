#include "rectangle.h"

Rectangle::Rectangle(): width(1), length(2){}

Rectangle::Rectangle(int w, int l): width(w), length(l){}

int Rectangle::getWidth(){return width;}

void Rectangle::setWidth(int w){width = w;}

int Rectangle::getLength(){return length;}

void Rectangle::setLength(int l){length = l;}

int Rectangle::area(){return width * length;}

void print(Rectangle &r){
    std::cout << " The Area of the Rectangle is : " << r.area() << std::endl;
}