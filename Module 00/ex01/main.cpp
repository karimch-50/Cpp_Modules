/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:22:10 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/15 16:10:21 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook	phoneBook;
	std::string	input;
	while (std::getline(std::cin, input))
	{
		std::cout << "Enter a command:" << std::endl;
		if (input == "ADD")
			phoneBook.addNewContact();
		else
			std::cout << "Invalid command!! HINT: (ADD, SEARCH, EXIT)" << std::endl;
		// 	//do somthing
		// else if (input == "SEARCH")
		// 	//do somthing
		if (input == "EXIT")
			return (0);
	}
	return (0);
}