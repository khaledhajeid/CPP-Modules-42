#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
    PhoneBook phonebook;
    std::string command;

    std::cout << "Welcome to My PhoneBook :)" << std::endl;

    while (true)
    {
        std::cout << "> Enter command (ADD, SEARCH, EXIT): ";
        
        if (!std::getline(std::cin, command))
        {
            std::cout << "\nBye Byeee :)" << std::endl;
            break;
        }

        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else if (command == "EXIT")
        {
            std::cout << "Bye Byeee :)" << std::endl;
            break;
        } 
        else if (!command.empty())
            std::cout << "Invalid command!!!! Only ADD, SEARCH, or EXIT are accepted." << std::endl;
    }

    return 0;
}