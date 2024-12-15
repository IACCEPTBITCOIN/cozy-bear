#ifndef A_H
#define A_H

class A {
private:
public:
    A();   
    void clear();  
    bool operator==(        ) const;
    friend std::ostream& operator<<(                );    
};

#endif