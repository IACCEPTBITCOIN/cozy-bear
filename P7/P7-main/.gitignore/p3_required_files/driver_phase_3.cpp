#include <iostream>

void menu(/* B container,  A container */)
{
    UserInterface ui; // create a UserInterface object
    int option = 0;
    do {
        std::cout << "LOGIN AS A OR C\n\n";
        std::cout << "1) A\n";
        std::cout << "2) C\n";
        std::cout << "3) Exit program\n";
        std::cout << "\nSelect: ";
        std::cin >> option;
        std::cout << "\n";

        switch(option) {
            case 1:
                // ui = new A_UI();
                break;
            case 2:
                // ui = new C_UI();
                break;
            case 3:
                std::cout << "EXITING PROGRAM\n\n";
                return;
            default:
                std::cout << "INVALID OPTION" << "\n";
        }        
        ui->menu(/* B container, A container */); // run the selected UI

    } while( option != 3 );
}

int main() 
{   
    std::cout << std::endl;

    // instantiate A container
    // instantiate B container
    // instantiate A container iterator
    // instantiate B container iterator
    // read into A container
    // read into B container

    // call the menu function

    // delete all dynamic memory

    std::cout << std::endl;
    return 0;
}