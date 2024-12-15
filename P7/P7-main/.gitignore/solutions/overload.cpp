#include <iostream>

class Course {
private:
    class Professor {
    public:
        std::string name;
        Professor(): name("Staff")
        {}
    };
    std::string number;
    Professor prof;
    static std::string college;
public:
    Course(): number("101"), prof() 
    {
    }
    std::string getNumber() const
    {
        return number;
    }
    void setNumber(const std::string &n)
    {
        number = n;
    }
    std::string getProfName() const
    {
        return prof.name;
    }
    void setProfName(const std::string &n)
    {
        prof.name = n;
    }
    static std::string getCollege()
    {
        return college;
    }
};
std::string Course::college = "QCC";

void print(Course &c) {
    std::cout << Course::getCollege() << " " << c.getNumber() << " " << c.getProfName() << "\n";
}



int main() {
    std::cout << std::endl;

    Course c;
    c.setNumber("580");
    c.setProfName("Smith");
    print(c);

    std::cout << std::endl;
    return 0;
}