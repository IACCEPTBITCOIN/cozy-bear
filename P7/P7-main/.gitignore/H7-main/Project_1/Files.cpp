#include "Files.h"
#include "Container.h"
#include <fstream> 
#include <iostream> 
#include <sstream> 

void FileRead::read(intArray& array)
{
    std::ifstream file("data.csv");

    if (!file.is_open()) {
        std:: cerr << "Error: data.csv does not exist" << std::endl;    // finished with the help of 1_exceptions.cpp and 
        return;                                                         // https://cplusplus.com/doc/tutorial/files/
    }

    std::string line;                           // declare line so it can be called in the while loop.

    while(std::getline(file, line) ) {   // read line of text from file into the variable line.             
        std::string token;                                             
        std::stringstream parser(line); 

    while( std::getline(parser, token, ',') ) {   // extract token separated by commas from line.
        int num = stoi(token);                         // convert token into integer.
        array.push_back(num);                         // store integer into array declared above.
    }

    file.close();                           // must always close so it the file doesn't lock or corrupt 
}



}
