/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 20:30:14 by ssukhija          #+#    #+#             */
/*   Updated: 2026/02/11 20:30:14 by ssukhija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook()
{
    index = 0;
    count = 0;
}
PhoneBook::~PhoneBook() {}


bool    is_letters(std::string str)
{
    size_t  i = 0;

    while (i < str.length())
    {
        if (!std::isalpha(str[i]) && str[i] != ' ' && str[i] != '-')
            return false;
        i++;
    }
    return true;
}

bool    is_numbers(std::string str)
{
    size_t  i = 0;

    while (i < str.length())
    {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

bool    check_valid(std::string type, std::string input)
{
    if (type == "first name" || type == "last name")
    {
        if (!is_letters(input))
        {
            std::cout << "Use LETTERS only please. ";
            return false;
        }
    }
    if (type == "phone number")
    {
        if (!is_numbers(input))
        {
            std::cout << "Use NUMBERS only please. ";
            return false;
        }
    }
    return true;
}


std::string get_input(std::string type)
{
    std::string input;

    while(true)
    {
        std::cout << "Please enter the " << type << ": ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "\nEOF detected. Exiting Phonebook.\n";
            std::exit(0);
        }
        if (!input.empty())
        {
            if (check_valid(type, input))
                return input;
        }
        std::cout << "Try again:\n";
    }
}

std::string  trunc_str(std::string str)
{
    if (str.length() <= 10)
        return (str);
    else
        return (str.substr(0,9).append("."));
}

void PhoneBook::list_contacts()
{
    std::string  input;
    int i = 0;

    if (count == 0)
    {
        std::cout << "Sorry not contacts stored in your phonebook." << "\n";
        return ;
    }
    std::cout << std::setw(10) << std::right << "Index"  << "|"
        << std::setw(10) << std::right << "First Name" << "|"
        << std::setw(10) << std::right << "Last Name" << "|"
        << std::setw(10) << std::right << "Nickname" << "\n"
        << "--------------------------------------------" << "\n";
    while(i < count)
    {
        std::cout << std::setw(10) << std::right << i << "|" <<
                std::setw(10) << std::right << trunc_str(contact[i].get_firstName()) << "|" <<
                std::setw(10) << std::right << trunc_str(contact[i].get_lastName()) << "|" <<
                std::setw(10) << std::right << trunc_str(contact[i].get_nickname()) << "|" <<
                "\n";
        i++;
    }
    show_contact();
}

void    PhoneBook::show_contact()
{
    std::string  input;
    int i;

    while(1)
    {
        input = get_input("index");
        if (input.length() == 1)
        {
            i = input[0] - '0';
            if (i >= 0 && i < count)
            {
                std::cout << "\n++++++++ CONTACT INFO ++++++++\n";
                std::cout << "first name" << std::setw(7) << ": " << contact[i].get_firstName() << "\n"
                    << "last name" << std::setw(8) << ": " << contact[i].get_lastName() << "\n"
                    << "nickname" << std::setw(9) << ": " << contact[i].get_nickname() << "\n"
                    <<  "phone number" << std::setw(5) << ": " << contact[i].get_phoneNum() << "\n"
                    << "darkest secret : " << contact[i].get_darkSecret() << "\n";
                std::cout << "++++++++++++++++++++++++++++++\n\n";
                return ;
            }
        }
        std::cout << "invalid choice, please try again...\n";
    }
}

void PhoneBook::add_contact()
{
    contact[index].set_firstName(get_input("first name"));
    contact[index].set_lastName(get_input("last name"));
    contact[index].set_nickname(get_input("nickname"));
    contact[index].set_phoneNum(get_input("phone number"));
    contact[index].set_darkSecret(get_input("darkest secret"));
    index = (index + 1) % 8;
    if (count < 8)
        count++;
}
