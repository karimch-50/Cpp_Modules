/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:25:16 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/15 16:02:39 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::getFirstName()
{
	return (firstName);
}

std::string	Contact::getLastName()
{
	return (lastName);
}

std::string	Contact::getNakeName()
{
	return (nakeName);
}

std::string	Contact::getDarkestSecret()
{
	return (darkestSecret);
}

int	Contact::getPhoneNumber()
{
	return (phoneNumber);
}

void	Contact::setFirstName(std::string _firstName)
{
	firstName = _firstName;
}

void	Contact::setLastName(std::string _lastName)
{
	lastName = _lastName;
}

void	Contact::setNakeName(std::string _nakeName)
{
	nakeName = _nakeName;
}

void	Contact::setDarkestSecret(std::string _darkestSecret)
{
	darkestSecret = _darkestSecret;
}

void	Contact::setPhoneNumber(int _phoneNumber)
{
	phoneNumber = _phoneNumber;
}


// void	Contact::createNewContact()
// {
// 	std::cout << "Enter your first name:" << std::endl;
// 	std::getline(std::cin, firstName);
// 	std::cout << "Enter your last name:" << std::endl;
// 	std::getline(std::cin, lastName);
// 	std::cout << "Enter your nake name:" << std::endl;
// 	std::getline(std::cin, nakeName);
// 	std::cout << "Enter your darkest secret:" << std::endl;
// 	std::getline(std::cin, darkestSecret);
// 	// std::cout << "Enter your phone number:" << std::endl;
// 	// std::getline(std::cin, phoneNumber);
// }
