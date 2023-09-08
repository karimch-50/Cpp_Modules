/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 06:45:22 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/08 19:42:50 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("Default")
{
	std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria Constructor with param called" << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria& _copy)
{
	std::cout << "AMateria Copy constructor called" << std::endl;
	*this = _copy;
}

AMateria& AMateria::operator=(const AMateria& _assignment)
{
	std::cout << "AMateria Copy assignment operator called" << std::endl;
	if (this != &_assignment)
		type = _assignment.type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << std::endl;
}
