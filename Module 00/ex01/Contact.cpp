/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:25:16 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/13 11:57:35 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::createNewContact()
{
	std::cout << "Enter your first name:" << std::endl;
	std::getline(std::cin, firstName);
	std::cout << "Enter your last name:" << std::endl;
	std::getline(std::cin, lastName);
	std::cout << "Enter your nake name:" << std::endl;
	std::getline(std::cin, nakeName);
	std::cout << "Enter your darkest secret:" << std::endl;
	std::getline(std::cin, darkestSecret);
	// std::cout << "Enter your phone number:" << std::endl;
	// std::getline(std::cin, phoneNumber);
}
