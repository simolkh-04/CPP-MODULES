#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
    index = 0;
    t_c = 0;
}
void PhoneBook::add()
{
    Contact lcontact;
    std::string input;

    while(1)
    {
        std::cout << "enter first_name" << std::endl;
        std::getline(std::cin, input);
        if(std::cin.eof() || std::cin.fail())
        {
            std::cout << "input canceled .." << std::endl;
            return;
        }
        if (input.empty())
        {
            std::cout << "first name cannot be empty ..." << std::endl;
            continue;
        }   
        lcontact.setFirstName(input);
        break;
    }
    
    while(1)
    {
        std::cout << "enter last_name" << std::endl;
        std::getline(std::cin, input);
        if(std::cin.eof() || std::cin.fail())
        {
            std::cout << "input canceled .." << std::endl;
            return;
        }
        if(input.empty())
        {
            std::cout << "last name cannot be empty ..." << std::endl;
            continue;
        }
        lcontact.setLastName(input);
        break;
    }

    while(1)
    {
        std::cout << "enter nickname" << std::endl;
        std::getline(std::cin, input);
        if(std::cin.eof() || std::cin.fail())
        {
            std::cout << "input canceled .." << std::endl;
            return;
        }
        if(input.empty())
        {
            std::cout << "nickname cannnot be empty ..." << std::endl;
            continue;
        }
        lcontact.setNickname(input);
        break;
    }

    while (1)
    {
        std::cout << "enter Phone_Number" << std::endl;
        std::getline(std::cin, input);
        if(std::cin.eof() || std::cin.fail())
        {
            std::cout << "input canceled .." << std::endl;
            return;
        }
        if(input.empty())
        {
            std::cout << "phone number cannot be empty ..." << std::endl;
            continue;
        }
        lcontact.setPhoneNumber(input);
        break;
    }
    
    while(1)
    {
        std::cout << "enter DarkestSecret" << std::endl;
        std::getline(std::cin, input);
        if(std::cin.eof() || std::cin.fail())
        {
            std::cout << "input canceled .." << std::endl;
            return;
        }
        if(input.empty())
        {
            std::cout << "darkest secret cannot be empty ..." << std::endl;
            continue;
        }
        lcontact.setDarkestSecret(input);
        break;
    }

    con[index] = lcontact;
    index = (index + 1) % 8;
    if(t_c < 8)
        t_c++; 
}

std::string formatColumn(std::string str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void PhoneBook::displayPhoneBook() {
    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname" << "|" << std::endl;

    for (int i = 0; i < t_c; i++) {
        std::cout << "|" << std::setw(10) << i
                  << "|" << std::setw(10) << formatColumn(con[i].getFirstName())
                  << "|" << std::setw(10) << formatColumn(con[i].getLastName())
                  << "|" << std::setw(10) << formatColumn(con[i].getNickname()) 
                  << "|" << std::endl;
    }
}

void PhoneBook::displayFullContact(int i) 
{
    std::cout << "First Name: " << con[i].getFirstName() << std::endl;
    std::cout << "Last Name: " << con[i].getLastName() << std::endl;
    std::cout << "Nickname: " << con[i].getNickname() << std::endl;
    std::cout << "Phone Number: " << con[i].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << con[i].getDarkestSecret() << std::endl;
}

void PhoneBook::search()
{
    if(t_c == 0)
    {
        std::cout << "phonebook is empty" << std::endl;
        return ;
    }

    this->displayPhoneBook();
    std::string str;
    std::cout << "enter index : ";
    int i;
    if(!(std::getline(std::cin, str)))
        return ;
    std::stringstream s(str);
    if(!(s >> i) || !s.eof())
    {
        std::cout << "error" << std::endl;
        return;
    }
    if(i >= 0 && i < t_c)
    {
        this->displayFullContact(i);
    }
    else{
        std::cout << "Invalid Index" << std::endl;
        return;
    }
}