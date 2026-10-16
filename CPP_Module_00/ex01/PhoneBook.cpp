#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    _contactCount = 0;
    _oldestIndex = 0;
}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::addContact()
{
    std::string input;
    Contact newContact;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, input);
    while (input.empty() && !std::cin.eof())
    {
        std::cout << "Field cannot be empty please enter First Name: ";
        std::getline(std::cin, input);
    }
    newContact.setFirstName(input);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, input);
    while (input.empty() && !std::cin.eof())
    {
        std::cout << "Field cannot be empty please enter Last Name: ";
        std::getline(std::cin, input);
    }
    newContact.setLastName(input);

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, input);
    while (input.empty() && !std::cin.eof())
    {
        std::cout << "Field cannot be empty please enter Nickname: ";
        std::getline(std::cin, input);
    }
    newContact.setNickname(input);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, input);
    while (input.empty() && !std::cin.eof())
    {
        std::cout << "Field cannot be empty please enter Phone Number: ";
        std::getline(std::cin, input);
    }
    newContact.setPhone(input);

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, input);
    while (input.empty() && !std::cin.eof())
    {
        std::cout << "Field cannot be empty please enter Darkest Secret: ";
        std::getline(std::cin, input);
    }
    newContact.setDarkestSecret(input);

    _contacts[_oldestIndex] = newContact;
    _oldestIndex++;

    if (_oldestIndex == 8)
        _oldestIndex = 0;
    
    if (_contactCount < 8)
        _contactCount++;

    std::cout << "Contact successfully added" << std::endl;
}

void PhoneBook::searchContact() const
{
    if (_contactCount == 0)
    {
        std::cout << "Phonebook is empty please add a contact first" << std::endl;
        return;
    }

    std::cout << std::setw(10) << std::right << "Index" << "|"
              << std::setw(10) << std::right << "First Name" << "|"
              << std::setw(10) << std::right << "Last Name" << "|"
              << std::setw(10) << std::right << "Nickname" << std::endl;

    for (int i = 0; i < _contactCount; i++)
    {
        std::string fName = _contacts[i].getFirstName();
        std::string lName = _contacts[i].getLastName();
        std::string nName = _contacts[i].getNickname();

        if (fName.length() > 10) fName = fName.substr(0, 9) + ".";
        if (lName.length() > 10) lName = lName.substr(0, 9) + ".";
        if (nName.length() > 10) nName = nName.substr(0, 9) + ".";

        std::cout << std::setw(10) << std::right << i << "|"
                  << std::setw(10) << std::right << fName << "|"
                  << std::setw(10) << std::right << lName << "|"
                  << std::setw(10) << std::right << nName << std::endl;
    }

    std::string input;
    int index;
    std::cout << "Enter the index of the contact to display: ";
    std::getline(std::cin, input);

    std::stringstream ss(input);
    if (ss >> index && ss.eof() && index >= 0 && index < _contactCount)
        _contacts[index].displayContact();
    else
        std::cout << "Invalid index please enter a valid number from the list." << std::endl;
}