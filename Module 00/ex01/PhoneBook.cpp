/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:25:44 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/15 20:06:27 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
}

int	PhoneBook::getIndex()
{
	return (index);
}


bool	allDigits(std::string str)
{
	int	i;

	i = 0;
	while (i < (int)str.size())
	{
		if (!std::isdigit(str[i]) && str[i] != '+')
			return (false);
		i++;
	}
	return (true);
}

void	PhoneBook::addNewContact()
{
	std::string firstName;
	std::string lastName;
	std::string nakeName;
	std::string darkestSecret;
	std::string	phoneNumber;

	std::cout << "Please enter your first name:";
	while(std::getline(std::cin, firstName))
	{
		if (firstName.empty())
		{
			std::cout << "First name is empty!!\n";
			std::cout << "Please enter your first name:";
			continue;
		}
		contacts[index % 3].setFirstName(firstName);
		break ;
	}
	std::cout << "Please enter your last name:";
	while(std::getline(std::cin, lastName))
	{
		if (lastName.empty())
		{
			std::cout << "Last name is empty!!\n";
			std::cout << "Please enter your last name:";
			continue;
		}
		contacts[index % 3].setLastName(lastName);
		break ;
	}
	std::cout << "Please enter your nake name:";
	while(std::getline(std::cin, nakeName))
	{
		if (nakeName.empty())
		{
			std::cout << "Nake name is empty!!\n";
			std::cout << "Please enter your nake name:";
			continue;
		}
		contacts[index % 3].setNakeName(nakeName);
		break ;
	}
	std::cout << "Please enter your darkest secret:";
	while(std::getline(std::cin, darkestSecret))
	{
		if (nakeName.empty())
		{
			std::cout << "Darkest secret is empty!!\n";
			std::cout << "Please enter your darkest secret:";
			continue;
		}
		contacts[index % 3].setDarkestSecret(darkestSecret);
		break ;
	}
	std::cout << "Please enter your phone number:";
	while(std::getline(std::cin, phoneNumber))
	{
		if (nakeName.empty())
		{
			std::cout << "Phone number is empty!!\n";
			std::cout << "Please enter your phone number:";
			continue;
		}
		if (allDigits(nakeName))
		{
			std::cout << "Please the phone number must have only numbers!!\n";
			std::cout << "Please enter your phone number:";
			continue;
		}
		int num = std::atoi(phoneNumber.c_str());
		contacts[index % 3].setPhoneNumber(num);
		break ;
	}
	this->index++;
}

// void	displayContacts(PhoneBook phoneBook)
// {
// 	int	i;

// 	std::cout << "|-----------|-----------|-----------|--------------|\n";
// 	std::cout << "| Fist Name | Last Name | Nake Name |Darkest Secret|\n";
// 	std::cout << "|-----------|-----------|-----------|--------------|\n";
// 	i = 0;
// 	while (i < phoneBook.getIndex())
// 	{
// 		std::cout << "|" << phoneBook.contacts[i].getFirstName() << "|";
// 		std::cout << phoneBook.contacts[i].getLastName() << "|";
// 		std::cout << phoneBook.contacts[i].getNakeName() << "|";
// 		std::cout << phoneBook.contacts[i].getDarkestSecret() << "|";
// 		std::cout << "|-----------|-----------|-----------|--------------|\n";
// 		i++;
// 	}
// }

void	PhoneBook::searchContact()
{
	int	i;

	std::cout << "|----------|----------|----------|----------|\n";
	std::cout << "| FistName | LastName | NakeName |DarkSecret|\n";
	std::cout << "|----------|----------|----------|----------|\n";
	i = 0;
	while (i < getIndex())
	{
		std::cout << "|";
		std::cout << std::setw(10 - contacts[i].getFirstName().size());
		std::cout << contacts[i].getFirstName() << "|";
		std::cout << std::setw(10 - contacts[i].getLastName().size());
		std::cout << contacts[i].getLastName() << "|";
		std::cout << std::setw(10 - contacts[i].getNakeName().size());
		std::cout << contacts[i].getNakeName() << "|";
		std::cout << std::setw(10 - contacts[i].getDarkestSecret().size());
		std::cout << contacts[i].getDarkestSecret() << "|\n";
		std::cout << "|----------|----------|----------|----------|\n";
		i++;
	}
}
