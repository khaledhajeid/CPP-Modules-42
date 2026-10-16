#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

class PhoneBook {
private:
    Contact _contacts[8];
    int _contactCount;
    int _oldestIndex;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContact() const;
};

#endif