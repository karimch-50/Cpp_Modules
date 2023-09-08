/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:17:31 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/08 19:47:41 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("Default")//, index(0)
{
	std::cout << "Character Default constructor called" << std::endl;
	int i = -1;
	while (++i < 4)
		inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << "Character Destructor called" << std::endl;
	//
}


Character::Character(const std::string& _name) : name(_name)
{
	std::cout << "Character Constructor with param called" << std::endl;
	//
}

/* Any copy
(using copy constructor or copy assignment operator)
of a Character must be deep*/

Character::Character(const Character& _copy)
{
	(void)_copy;
	std::cout << "Character Copy constructor called" << std::endl;
	//
}

const Character& Character::operator=(const Character& _assignment)
{
	(void)_assignment;
	std::cout << "Character Copy assignment operator called" << std::endl;
	//
	return (*this);
}

std::string const & Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	(void)m;
	//
}

void Character::unequip(int idx)
{
	(void)idx;
	//
}

void Character::use(int idx, ICharacter& target)
{
	(void)idx;
	(void)target;
	//
}
