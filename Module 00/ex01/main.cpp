/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:22:10 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/13 12:00:02 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook	phoneBook;
	std::string	input;
	while (1)
	{
		std::cout << "Enter a command:" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			Contact	newContact;
			newContact.createNewContact();
			// phoneBook.addNewContact(newContact);
		}
		else
			std::cout << "Invalid command!! HINT: (ADD, SEARCH, EXIT)";
		// 	//do somthing
		// else if (input == "SEARCH")
		// 	//do somthing
		if (input == "EXIT")
			return (0);
	}
	return (0);
}