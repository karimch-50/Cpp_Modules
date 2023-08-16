/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:22:10 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/15 19:35:49 by kchaouki         ###   ########.fr       */
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
		std::cout << "Enter a command:";
		if (!std::getline(std::cin, input))
			break ;
		if (input == "ADD")
			phoneBook.addNewContact();
		else if (input == "SEARCH")
			phoneBook.searchContact();
		else if (input == "EXIT")
			return (0);
		else
			std::cout << "Invalid command!! \n\tHINT: (ADD, SEARCH, EXIT)" << std::endl;
	}
	return (0);
}