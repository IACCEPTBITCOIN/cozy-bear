#include <iostream>
#include <vector>                                           // include the stl dynamic array container

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

template<typename T>                            
void print(std::vector<T> &vec)                             // vector of type T            
{
    typename std::vector<T>::iterator it = vec.begin();     // typename keyword required to specify an iterator for a vector of type T      
    while( it != vec.end() ) {                              // advance the iterator until the end of the vector
        std::cout << *it << " ";                            // overloaded * returns the current object accessed by the iterator
        ++it;                                               // overloaded ++ to advance the iterator forward
    }
    std::cout << "\n";
}
template<typename T>                            
void print(std::vector<T*> &vec)                            // specialization for vectors of pointers of type T
{
    auto it = vec.begin();                                  // auto keyword enables the compiler to automatically derive the type from the context of the statement              
    while( it != vec.end() ) {
        std::cout << **it << " ";                           // * required to deference the pointer that is returned by *it   
        ++it;
    }
    std::cout << "\n";
}

int main() {
    std::cout << std::endl;
    
    std::vector<Shape> s;                                   // instantiate a vector of shape objects  
    s.push_back( Shape("Circle") );                         // store a shape object
    s.push_back( Shape("Square") );
    s.push_back( Shape("Triangle") );    
    print(s);

    std::vector<Shape*> sp;                                 // instantiate a vector of shape object pointers   
    sp.push_back( new Shape("Circle") );                    // store a pointer to a dynamic shape object
    sp.push_back( new Shape("Square") );
    sp.push_back( new Shape("Triangle") );    
    print(sp);

    std::cout << std::endl;
    return 0;
}