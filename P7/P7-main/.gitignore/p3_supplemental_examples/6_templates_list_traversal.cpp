#include <iostream>
#include <list>

class Shape {
private:
    std::string name;
public:
    Shape(std::string n):name(n) {}
    friend std::ostream& operator<<(std::ostream &o, const Shape &t);   
};
std::ostream& operator<<(std::ostream &o, const Shape &t) { 
    o << t.name;
    return o;
}

int main() {
    std::cout << std::endl;

    std::list<Shape*> list;                             // STL dynamic array (listtor)
    std::list<Shape*>::iterator it;                     // STL iterator for a dynamic array

    list.push_back( new Shape("Circle") );              // store pointers to dynamic objects
    list.push_back( new Shape("Rectangle") );
    list.push_back( new Shape("Square") );
    list.push_back( new Shape("Triangle") );
    list.push_back( new Shape("Rhombus") );
    list.push_back( new Shape("Trapezoid") );          

    for(Shape* p : list) {                              // ranged for loop to read the list using an iterator (simple syntax relative to normal for loop
        std::cout << *p << " ";                         // p points to value pointed to by the loop iterator                              
    }
    std::cout << "\n"; 

    for(it = list.begin(); it != list.end(); ++it) {    // for loop to read the list using an iterator (identical to the while loop in earlier examples)
        std::cout << **it << " ";                       // * required to deference the pointer that is returned by *it
    }
    std::cout << "\n";

    for(it = list.begin(); it != list.end(); ) {        // for loop to erase the dynamic memory pointed to by the list (this is tricky)
        delete *it;                                     // delete will remove the object from the list
        it = list.erase(it);                            // erase will remove the stored pointer AND reset the iterator to point to the next value to erase (important)                                                                                                   
    }

    list.clear();                                       // reset the list to its default state (can be used to empty a list if dynamic memory is not used)      

    std::cout << std::endl;
    return 0;
}