#include "Contact.hpp"

Contact::Contact()
{

}
Contact::~Contact()
{

}
void Contact::setFirstName(std::string firstName)
{
    _firstName = firstName;
}
void Contact::setLastName(std::string lastName)
{
    _lastName = lastName;
}
void Contact::setNickname(std::string nickname)
{
    _nickname = nickname;
}
void Contact::setPhone(std::string phone)
{
    _phone = phone;
}
void Contact::setDarkestSecret(std::string darkestSecret)
{
    _darkestSecret = darkestSecret;
}
std::string Contact::getFirstName() const
{
    return _firstName;
}

std::string Contact::getLastName() const
{
    return _lastName;
}

std::string Contact::getNickname() const
{
    return _nickname;
}

void Contact::displayContact() const
{
    std::cout << "First Name: " << _firstName << std::endl;
    std::cout << "Last Name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone Number: " << _phone << std::endl;
    std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}