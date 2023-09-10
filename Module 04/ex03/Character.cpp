/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:17:31 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/10 19:19:51 by kchaouki         ###   ########.fr       */
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

static bool checkInventory(AMateria** inventory, AMateria* m)
{
	int i = -1;
	while (++i < 4)
	{
		if (inventory[i] && inventory[i] == m)
			return (false);
	}
	return (true);
}

Character::~Character()
{
	std::cout << "Character Destructor called" << std::endl;
	int i = 0;
	while (i < 4)
	{
		if (checkInventory(trachInventory, inventory[i]) == false)
			delete inventory[i];
		else
		{
			delete inventory[i];
			delete trachInventory[i];		
		}
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

static void	freeTrachInventory(AMateria** trachInventory, AMateria** Inventory)
{
	int i = -1;

	while (++i < 4)
	{
		if (checkInventory(Inventory, trachInventory[i]) == true)
		{
			delete trachInventory[i];
			trachInventory[i] = NULL;
		}
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
	freeTrachInventory(trachInventory, inventory);
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
