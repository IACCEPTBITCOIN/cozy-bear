#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

class Triangle{
private:
    int width;
    int height;

public:
    Triangle();
    Triangle(int w, int h);

    int getWidth();
    int getHeight();

    void setWidth(int w);
    void setHeight(int h);

    int area();    

};

void print(Triangle &t);
#endif