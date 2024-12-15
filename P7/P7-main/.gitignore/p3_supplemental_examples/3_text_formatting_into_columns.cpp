// S. Trowbridge 2023
#include <iostream>
#include <iomanip> // required for setw and left/right commands for column format

int main() {
    std::cout << std::endl;

    // organize text into left aligned columns where each column is a specific width
    std::cout << std::left << std::setw(6) << "1011" << std::setw(20) << "John Smith" << std::setw(8) << "90210" << std::endl;
    std::cout << std::left << std::setw(6) << "4422" << std::setw(20) << "Adrian Moreau" << std::setw(8) << "19154" << std::endl;
    std::cout << std::left << std::setw(6) << "1011" << std::setw(20) << "Michael Damont" << std::setw(8) << "92340" << std::endl;        
    
    std::cout << std::endl;
    return 0;
}