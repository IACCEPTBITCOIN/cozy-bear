#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle {
private:
    int width;
    int length;

public:
    Rectangle();
    Rectangle(int w, int l);

    int getWidth();
    int getLength();

    void setWidth(int w);
    void setLength(int l);

    int area();

};

void print(Rectangle &r);
#endif