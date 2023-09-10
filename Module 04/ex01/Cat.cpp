/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:32:54 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/09 19:10:32 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Default constructor called" << std::endl;
	brain = new Brain();
	for (int i = 0; i < 100; i++)
		brain->Ideas[i] = "Cat idea";
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete brain;
}

Cat::Cat(const Cat& _copy) : Animal(_copy)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	brain = new Brain(*_copy.brain);
	*this = _copy;
}

Cat& Cat::operator=(const Cat& _assignment)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &_assignment)
	{
		delete brain;
		brain = new Brain(*_assignment.brain);
		type = _assignment.type;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat: Meaw Meaw" << std::endl;
}
