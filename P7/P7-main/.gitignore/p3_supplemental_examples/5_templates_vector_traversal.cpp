#include <iostream>
#include <vector>

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

    std::vector<Shape*> v;                          // STL dynamic array (vector)
    std::vector<Shape*>::iterator it;               // STL iterator for a dynamic array

    v.push_back( new Shape("Circle") );             // store pointers to dynamic objects
    v.push_back( new Shape("Rectangle") );
    v.push_back( new Shape("Square") );
    v.push_back( new Shape("Triangle") );
    v.push_back( new Shape("Rhombus") );
    v.push_back( new Shape("Trapezoid") );        

    for(Shape* p : v) {                             // ranged for loop to read the vector using an iterator (simple syntax relative to normal for loop
        std::cout << *p << " ";                     // p points to value pointed to by the loop iterator                              
    }
    std::cout << "\n"; 

    for(it = v.begin(); it != v.end(); ++it) {      // for loop to read the vector using an iterator (identical to the while loop in earlier examples)
        std::cout << **it << " ";                   // * required to deference the pointer that is returned by *it
    }
    std::cout << "\n";

    for(int i=0; i <v.size(); ++i) {                // for loop read the vector using indicies
        std::cout << *(v[i]) << " ";                // * required to deference the pointer that is returned by v[i]
    } 
    std::cout << "\n";  

    for(it = v.begin(); it != v.end(); ) {         // for loop to erase the dynamic memory pointed to by the vector (this is tricky)
        delete *it;                                // delete will remove the object from the list
        it = v.erase(it);                          // erase will remove the stored pointer AND reset the iterator to point to the next value to erase (important)                                                                                                   
    }

    v.clear();                                     // reset the vector to its default state (can be used to empty a vector if dynamic memory is not used)      

    std::cout << std::endl;
    return 0;
}