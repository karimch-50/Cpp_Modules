/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:24:49 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/10 17:03:48 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default constructor called" << std::endl;
	int i = -1;
	while (++i < 4)
		inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor called" << std::endl;
	int i = 0;
	while (i < 4)
		delete inventory[i++];
}

MateriaSource::MateriaSource(const MateriaSource& _copy)
{
	std::cout << "MateriaSource Copy constructor called" << std::endl;
	int i = -1;
	while (++i < 4)
		inventory[i] = NULL;
	*this = _copy;
}

const MateriaSource& MateriaSource::operator=(const MateriaSource& _assignment)
{
	int	i = -1;

	std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	if (this != &_assignment)
	{
		while (++i < 4)
		{
			if (inventory[i] != NULL)
				delete inventory[i];
			if (_assignment.inventory[i])
				inventory[i] = _assignment.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}	
	}
	return (*this);
}

static bool checkInventory(AMateria** inventory, AMateria* m)
{
	int i = -1;
	while (++i < 4)
	{
		if (inventory[i] == m)
			return (false);
	}
	return (true);
}

void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	if (m != NULL)
	{
		while (i < 4 && inventory[i] != NULL){i++;}
		if (i < 4)
		{
			if (!checkInventory(inventory, m))
				inventory[i] = m->clone();
			else
				inventory[i] = m;
		}
		else
		{
			std::cout << "MateriaSource can't add more AMateria Cuz inventory is full!!" << std::endl;
			if (checkInventory(inventory, m))
			{
				std::cout << "deleting ..." << std::endl;
				delete m;
			}
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while (i < 4)
	{
		if (inventory[i] != NULL && inventory[i]->getType() == type)
			return (inventory[i]->clone());
		i++;
	}
	return (NULL);
}
