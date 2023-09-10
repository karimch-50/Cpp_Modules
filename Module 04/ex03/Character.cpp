/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:17:31 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/10 13:49:35 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Default")
{
	std::cout << "Character Default constructor called" << std::endl;
	int i = -1;
	while (++i < 4)
	{
		inventory[i] = NULL;
		trachInventory[i] = NULL;
	}
}

// bool	hasAlredyInNewInventory(AMateria** inventory, AMateria* m)
// {
// 	int	i = -1;

// 	while (++i < 4)
// 	{
// 		if (inventory[i] == m)
// 			return (true);
// 	}
// 	return (false);
// }

// AMateria**	prepareDeleteInventory(AMateria** inventory)
// {
// 	AMateria** newInventory = new AMateria*[4];
// 	int i = -1;

// 	while (++i < 4)
// 		newInventory[i] = NULL;
// 	i = -1;
// 	int j;
// 	while (++i < 4)
// 	{
// 		if (!hasAlredyInNewInventory(newInventory, inventory[i]))
// 		{
// 			j = 0;
// 			while (j < 4 && newInventory[j] != NULL)
// 				j++;
// 			newInventory[j] = inventory[i];
// 		}
// 	}
// 	return (newInventory);
// }

// Character::~Character()
// {
// 	std::cout << "Character Destructor called" << std::endl;
// 	int i = 0;
// 	AMateria**	toDelete1 = prepareDeleteInventory(inventory);
// 	AMateria**	toDelete2 = prepareDeleteInventory(trachInventory);
// 	while (i < 4)
// 	{
// 		delete toDelete1[i];
// 		delete toDelete2[i];		
// 		i++;
// 	}
// 	delete [] toDelete1;
// 	delete [] toDelete2;
// }

Character::~Character()
{
	std::cout << "Character Destructor called" << std::endl;
	int i = 0;
	while (i < 4)
	{
		delete inventory[i];
		delete trachInventory[i];		
		i++;
	}
}

Character::Character(const std::string& _name) : name(_name)
{
	std::cout << "Character Constructor with param called" << std::endl;
	int i = -1;
	while (++i < 4)
	{
		inventory[i] = NULL;
		trachInventory[i] = NULL;
	}
}

Character::Character(const Character& _copy)
{
	std::cout << "Character Copy constructor called" << std::endl;
	int i = -1;
	while (++i < 4)
	{
		inventory[i] = NULL;
		trachInventory[i] = NULL;
	}
	*this = _copy;
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

static void	freeTrachInventory(AMateria** trachInventory, AMateria** Inventory)
{
	int i = -1;

	while (++i < 4)
	{
		if (!checkInventory(Inventory, trachInventory[i]))
			delete trachInventory[i];
		trachInventory[i] = NULL;
	}	
}

const Character& Character::operator=(const Character& _assignment)
{
	int	i = -1;

	std::cout << "Character Copy assignment operator called" << std::endl;
	if (this != &_assignment)
	{
		name = _assignment.name;
		while (++i < 4)
		{
			if (inventory[i] != NULL)
				delete inventory[i];
			if (trachInventory[i] != NULL)
				delete trachInventory[i];
			if (_assignment.inventory[i])
				inventory[i] = _assignment.inventory[i]->clone();
			else
				inventory[i] = NULL;
			trachInventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	freeTrachInventory(trachInventory, inventory);
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
			std::cout << "Character can't add more AMateria Cuz inventory is full!!" << std::endl;
			if (checkInventory(inventory, m))
			{
				std::cout << "deleting ..." << std::endl;
				delete m;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if (idx > -1 && idx < 4 && inventory[idx])
	{
		if (!checkInventory(trachInventory, inventory[idx]))
			trachInventory[idx] = inventory[idx]->clone();
		else
			trachInventory[idx] = inventory[idx];
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (inventory[idx])
		inventory[idx]->use(target);
}
