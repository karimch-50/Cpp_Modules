/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:32:50 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/07 14:32:20 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const std::string& _type)
{
	std::cout << "Animal Constructor with param called" << std::endl;
	type = _type;
}

Animal::Animal(const Animal& _copy)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = _copy;
}

Animal& Animal::operator=(const Animal& _assignment)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &_assignment)
		type = _assignment.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal: animal make sound" << std::endl;
}

const std::string&	Animal::getType(void) const
{
	return (type);
}
