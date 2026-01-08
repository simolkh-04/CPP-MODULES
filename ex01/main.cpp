/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhal <mlakhal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:35:09 by mlakhal           #+#    #+#             */
/*   Updated: 2026/01/08 15:54:40 by mlakhal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


int main()
{
    std::string input;
    PhoneBook phone;

    while (1)
    {
        std::cout << "enter command : ADD , SEARCH or EXIT" << std::endl;
        std::getline(std::cin, input);
        if(std::cin.eof() || std::cin.fail())
        {
            std::cout << "FAILED ..." << std::endl;
            break;
        }
        if (input == "ADD")
        {
            phone.add();
        }
        else if (input == "SEARCH")
        {
            phone.search();
        }
        else if (input == "EXIT")
        {
            std::cout << "good bye" << std::endl; 
            break;
        }
    }
    return (0);
}