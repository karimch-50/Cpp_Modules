/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:41:59 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/06 18:55:31 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():Name("Unknown"), HitPoint(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name): HitPoint(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "ClapTrap Constructor with param called" << std::endl;
	Name = _name;
}

ClapTrap::ClapTrap(const ClapTrap& _copy)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = _copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& _assignment)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &_assignment)
	{
		Name = _assignment.Name;
		HitPoint = _assignment.HitPoint;
		EnergyPoints = _assignment.EnergyPoints;
		AttackDamage = _assignment.AttackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (HitPoint > 0 && EnergyPoints > 0)
	{
		std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
		EnergyPoints--;
	}
	else
		std::cout << "ClapTrap can't do anything if it has no hit points or energy points lef" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (HitPoint > 0 && EnergyPoints > 0)
	{
		std::cout << "ClapTrap " << Name << " take " << amount << " points of damage!" << std::endl;
		AttackDamage -= amount;
		HitPoint -= amount;
	}
	else
		std::cout << "ClapTrap can't do anything if it has no hit points or energy points lef" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (HitPoint > 0 && EnergyPoints > 0)
	{
		std::cout << "ClapTrap " << Name << " Repaired " << amount << " points!" << std::endl;
		HitPoint += amount;
		EnergyPoints--;
	}
	else
		std::cout << "ClapTrap can't do anything if it has no hit points or energy points lef" << std::endl;
}
