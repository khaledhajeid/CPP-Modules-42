#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phone;
        std::string _darkestSecret;
    public:
        Contact();
        ~Contact();

        void setFirstName(std::string firstName);
        void setLastName(std::string lastName);
        void setNickname(std::string nickname);
        void setPhone(std::string phone);
        void setDarkestSecret(std::string darkestSecret);

        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;

        void displayContact() const;
};

#endif