/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:25:44 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/15 16:34:15 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
}

void	PhoneBook::addNewContact()
{
	std::string firstName;
	std::string lastName;
	std::string nakeName;
	std::string darkestSecret;

	int	ok;

	ok = 0;
	while(std::getline(std::cin, firstName) && !ok)
	{
		ok = 1;
		if (firstName.empty())
		{
			std::cout << "Please fill the first name!!";
			ok = 0;
		}
		if (contacts[index].setFirstName(firstName))
		{
			std::cout << "Please enter a valid name!!";
			ok = 0;
		}	
	}
	
}