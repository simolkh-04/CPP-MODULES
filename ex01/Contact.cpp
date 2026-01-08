/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhal <mlakhal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 14:30:40 by mlakhal           #+#    #+#             */
/*   Updated: 2026/01/08 16:12:09 by mlakhal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string input)
{
    first_name = input;
}
void Contact::setLastName(std::string input)
{
    last_name = input;
}
void Contact::setNickname(std::string input)
{
    nickname = input;
}
void Contact::setPhoneNumber(std::string input)
{
    phone_number = input;
}
void Contact::setDarkestSecret(std::string input)
{
    darkest_secret = input;
}

std::string Contact::getFirstName()
{
    return first_name;
}
std::string Contact::getLastName()
{
    return last_name;
}
std::string Contact::getNickname()
{
    return nickname;
}
std::string Contact::getPhoneNumber()
{
    return phone_number;
}
std::string Contact::getDarkestSecret()
{
    return darkest_secret;
}