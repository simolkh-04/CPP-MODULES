#ifndef CONTACT_HPP
#define CONTACT_HPP

#include<iostream>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        void setFirstName(std::string input);
        void setLastName(std::string input);
        void setNickname(std::string input);
        void setPhoneNumber(std::string input);
        void setDarkestSecret(std::string input);

        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
};
#endif