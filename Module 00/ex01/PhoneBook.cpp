/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:25:44 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/20 19:13:56 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
}

bool	allDigits(std::string str)
{
	int	i;

	i = 0;
	if (str[0] == '+')
		i++;
	while (i < (int)str.size())
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	PhoneBook::addNewContact()
{
	std::string firstName;
	std::string lastName;
	std::string nakeName;
	std::string darkestSecret;
	std::string phoneNumber;

	while(true)
	{
		std::cout << "Please enter your first name:";
		if (!std::getline(std::cin, firstName))
			return (1);
		if (firstName.empty())
		{
			std::cout << "First name is empty!!\n";
			continue;
		}
		contacts[index % 8].setFirstName(firstName);
		break ;
	}
	while(true)
	{
		std::cout << "Please enter your last name:";
		if (!std::getline(std::cin, lastName))
			return (1);
		if (lastName.empty())
		{
			std::cout << "Last name is empty!!\n";
			continue;
		}
		contacts[index % 8].setLastName(lastName);
		break ;
	}
	while(true)
	{
		std::cout << "Please enter your nake name:";
		if (!std::getline(std::cin, nakeName))
			return (1);
		if (nakeName.empty())
		{
			std::cout << "Nake name is empty!!\n";
			continue;
		}
		contacts[index % 8].setNakeName(nakeName);
		break ;
	}
	while(true)
	{
		std::cout << "Please enter your darkest secret:";
		if (!std::getline(std::cin, darkestSecret))
			return (1);
		if (darkestSecret.empty())
		{
			std::cout << "Darkest secret is empty!!\n";
			continue;
		}
		contacts[index % 8].setDarkestSecret(darkestSecret);
		break ;
	}
	while(true)
	{
		std::cout << "Please enter your phone number:";
		if (!std::getline(std::cin, phoneNumber))
			return (1);
		if (phoneNumber.empty())
		{
			std::cout << "Phone Number is empty!!\n";
			continue;
		}
		if (!allDigits(phoneNumber))
		{
			std::cout << "Invalide Phone number!!\n";
			continue;
		}
		if (phoneNumber.length() > 10)
		{
			std::cout << "Phone number Must have 10 digits!!\n";
			continue;
		}
		contacts[index % 8].setPhoneNumber(phoneNumber);
		break ;
	}
	this->index++;
	return (0);
}

void	PhoneBook::getAllInfos()
{
	std::string	_index;
	int			i;

	std::cout << "Please enter the index of a contact if you want more infos:";
	if (!std::getline(std::cin, _index))
		return ;
	i = _index[0] - '0';
	if (!allDigits(_index) || _index.length() > 1 || i > 7 || i > (index - 1))
	{
		std::cout << "Invalide input" << std::endl;
		return ;
	}
	std::cout << "First Name :" << contacts[i].getFirstName() << "\n";
	std::cout << "Last Name :" << contacts[i].getLastName() << "\n";
	std::cout << "Nake Name :" << contacts[i].getNakeName() << "\n";
	std::cout << "Darkest Secret :" << contacts[i].getDarkestSecret() << "\n";
	std::cout << "Phone Number :" << contacts[i].getPhoneNumber() << std::endl;
}

void	PhoneBook::searchContact()
{
	int	i;
	int	size;

	if (index > 0)
	{
		std::cout << "/-------------------------------------------\\\n";
		std::cout << "|   Index  | FistName | LastName | NakeName |\n";
		std::cout << "|----------|----------|----------|----------|\n";
		i = 0;
		size = (index > 8) ? 8 : index;
		while (i < size)
		{
			
			std::cout << "|";
			std::cout << std::setw(10) <<  i << "|";
			if (contacts[i].getFirstName().size() >= 10)
				std::cout << std::setw(10) <<  contacts[i].getFirstName().erase(9) + "." << "|";
			else
				std::cout << std::setw(10) <<  contacts[i].getFirstName() << "|";
			if (contacts[i].getLastName().size() >= 10)
				std::cout << std::setw(10) << contacts[i].getLastName().erase(9) + '.' << "|";
			else
				std::cout << std::setw(10) << contacts[i].getLastName() << "|";
			if (contacts[i].getNakeName().size() >= 10)
				std::cout << std::setw(10) << contacts[i].getNakeName().erase(9) + '.' << "|\n";
			else
				std::cout << std::setw(10) << contacts[i].getNakeName() << "|\n";
			std::cout << "|----------|----------|----------|----------|" << std::endl;
			i++;
		}
		getAllInfos();
	}
	else
		std::cout << "Please add some contacts !!" << std::endl;
}
