#ifndef B_H
#define B_H

class B {
private:
public:
    B();
    void clear();  
    bool operator==(        ) const;
    friend std::ostream& operator<<(                );    
};

#endif