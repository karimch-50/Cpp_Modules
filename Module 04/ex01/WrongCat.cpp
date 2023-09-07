/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:34:30 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/07 19:09:48 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& _copy) : WrongAnimal(_copy)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = _copy;
}

WrongCat& WrongCat::operator=(const WrongCat& _assignment)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &_assignment)
		type = _assignment.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat: Meaw Meaw" << std::endl;
}
