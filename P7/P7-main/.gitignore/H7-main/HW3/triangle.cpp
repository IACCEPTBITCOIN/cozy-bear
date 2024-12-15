#include "triangle.h"


Triangle::Triangle(): width(2), height(1){}

Triangle::Triangle(int w, int h): width(w), height(h){}

int Triangle::getWidth(){return width;}

void Triangle::setWidth(int w){width = w;}

int Triangle::getHeight(){return height;}

void Triangle::setHeight(int h){height = h;}

int Triangle::area(){return (width * height) / 2;}

void print(Triangle &t){
    std::cout << " The Area of the Triangle is : " << t.area() << std::endl;
}