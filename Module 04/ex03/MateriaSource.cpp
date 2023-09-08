/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:24:49 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/08 19:04:03 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default constructor called" << std::endl;
	//
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor called" << std::endl;
	//
}

MateriaSource::MateriaSource(const MateriaSource& _copy)
{
	(void)_copy;
	std::cout << "MateriaSource Copy constructor called" << std::endl;
	//
}

const MateriaSource& MateriaSource::operator=(const MateriaSource& _assignment)
{
	(void)_assignment;
	std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	//
	return (*this);
}

void MateriaSource::learnMateria(AMateria*)
{
	//
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	(void)type;
	//
	return (NULL);
}
