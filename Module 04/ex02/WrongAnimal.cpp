/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:31:20 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/07 14:33:14 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& _type)
{
	std::cout << "WrongAnimal Constructor with param called" << std::endl;
	type = _type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& _copy)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = _copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& _assignment)
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this != &_assignment)
		type = _assignment.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal: wrong animal make sound" << std::endl;
}

const std::string&	WrongAnimal::getType(void) const
{
	return (type);
}
