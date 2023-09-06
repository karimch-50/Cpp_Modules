/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:20:01 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/06 19:09:19 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	Name = "Unknown";
	HitPoint = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string _name):ClapTrap(_name)
{
	std::cout << "ScavTrap Constructor with param called" << std::endl;
	HitPoint = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& _copy):ClapTrap(_copy)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = _copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& _assignment)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &_assignment)
	{
		Name = _assignment.Name;
		HitPoint = _assignment.HitPoint;
		EnergyPoints = _assignment.EnergyPoints;
		AttackDamage = _assignment.AttackDamage;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (HitPoint > 0 && EnergyPoints > 0)
	{
		std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
		EnergyPoints--;
	}
	else
		std::cout << "ScavTrap can't do anything if it has no hit points or energy points lef" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << Name << " is now in Gate keeper mode" << std::endl;
}
