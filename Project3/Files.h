#ifndef FILES_H                          
#define FILES_H

#include <list>                     
#include <fstream>                      
#include <sstream>                      
#include <iomanip>                      
#include <iostream>                     
#include "Customer.h"                                   // THE USE OF INLINE SOLVED A "multiple definition issue" compiler issue
#include "Package.h"     

inline void readCustomers(std::list<Customer*>& customers) {
    std::ifstream file("Customer.csv");   // Open the Customer CSV file.
    if (!file.is_open()) {                // Check if the file opened successfully.
        std::cerr << "Error: Unable to open Customer.csv\n";
        return;
    }

    std::string line;
    std::getline(file, line);             // Skip the header line. (Michael Byrd-inspired CSV structure handling)
    while (std::getline(file, line)) {    // Read each line from the file.
        std::istringstream stream(line);
        std::string idStr, name;

        // Adjusted parsing logic for CSV format with proper handling of fields.
        if (std::getline(stream, idStr, ',') &&
            std::getline(stream, name, ',')) {

            try {
                
                int id = std::stoi(idStr);            // Convert ID to integer.

                customers.push_back(new Customer(name, id)); // Dynamically allocate Customer.

            } catch (const std::exception& e) {
                std::cerr << "Error: Failed to convert values in line -> " << line << "\n";
            }
        } else {
            std::cerr << "Error: Failed to parse line -> " << line << "\n";
        }
    }
    file.close();                         // Close the file after reading.
}


inline void readPackages(std::list<Package*>& packages) {
    std::ifstream file("Package.csv");    
    if (!file.is_open()) {                
        std::cerr << "Error: Unable to open Package.csv\n";
        return;
    }
    std::string line;
    std::getline(file, line);             
    while (std::getline(file, line)) {   
        std::istringstream stream(line);
        std::string idStr, name, maxPackagesStr;

        if (std::getline(stream, idStr, ',') && 
            std::getline(stream, name) &&
            std::getline(stream, maxPackagesStr)) {

            try {
                int id = std::stoi(idStr);                                 // Convert ID to integer.

                int maxPackages = std::stoi(maxPackagesStr);              // Convert maxPackages to integer.

                name.erase(name.find_last_not_of(" \n\r\t") + 1);            // Remove trailing whitespace.

                packages.push_back(new Package(name, id, maxPackages));     // Dynamically allocate Package.

            } catch (const std::exception& e) {
                std::cerr << "Error: Failed to convert values in line -> " << line << "\n";
            }
        } else {
            std::cerr << "Error: Failed to parse line -> " << line << "\n";
        }
    }
    file.close();                        
}

template<typename T>
void print(const std::list<T*>& container) {
    int columnWidth = 10;                                         // Adjusted the width of each column for better spacing.  // Adjusted 15 to 10 to avoid sapce as shown Package ID:    101, Type: Electronics to Package ID: 101, Type: Electronics //MICHAEL
    for (auto it = container.begin(); it != container.end(); ++it) {  
        if (*it) {                                                              // Check if pointer is valid before dereferencing.
            std::cout << std::setw(columnWidth) << std::left << **it << "\n";  // Print each object's data in a formatted row.
        } else {
            std::cerr << "Debug to continue\n"; 
        }
    }
}


template<typename T>
void clear(std::list<T*>& container) {
    for (auto it = container.begin(); it != container.end(); ++it) {  
        delete *it;                      // Delete each dynamically allocated object.
    }
    container.clear();                   // Clear the container.    
}

#endif                                   