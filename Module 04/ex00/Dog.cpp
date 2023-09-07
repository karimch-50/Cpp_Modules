/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:32:59 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/07 19:08:43 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog& _copy) : Animal(_copy)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = _copy;
}

Dog& Dog::operator=(const Dog& _assignment)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &_assignment)
		type = _assignment.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog: Haw Haw" << std::endl;
}
