/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhal <mlakhal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:27:36 by mlakhal           #+#    #+#             */
/*   Updated: 2026/01/08 16:10:45 by mlakhal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include<iostream>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact con[8];
        int index;
        int t_c;
    public:
        PhoneBook();
        void add();
        void displayPhoneBook();
        void search();
        void displayFullContact(int i);         
};


#endif