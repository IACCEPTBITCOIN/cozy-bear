// S. Trowbridge 2024
#include <iostream>
#include <fstream>                              // required for ifstream/ofstream file bjects
#include <sstream>                              // used for parsing and conversion

struct Info {
    std::string country;
    std::string state;
    int population;
};

void print(Info &i) {
    std::cout << i.country << " "
              << i.state << " "
              << i.population << "\n";
}

int main( ) {
    std::cout << std::endl;

    std::ifstream file("data_2.csv");           // open a file in the same directory                      

    std::string line, temp;                     // variable to store a line of text, variable to temporarily store data for conversion

    while( std::getline(file, line) ) {         // read one line of the file into the variable line

        Info i;                                 // create an info object to store one line of file data

        std::stringstream parser(line);         // create a variable for parsing each token in a line of text

        std::getline(parser, i.country, ',');   // read 1st value into the data member country (assumes the file is using , delimiters)
        std::getline(parser, i.state, ',');     // read 2nd value into the data member state
        std::getline(parser, temp, ',');        // read 3rd value into temp

        std::stringstream converter(temp);      // create a variable to to converting strings to other types
        converter >> i.population;              // convert temp into an int and store into the data member population

        print(i);                               // print the info object
    }

    file.close();                               // close the file     

    std::cout << std::endl;
    return 0;
}
