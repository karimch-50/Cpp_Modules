/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:24:08 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/07 12:20:01 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->Name = "default";
	ClapTrap::Name = this->Name + "_clap_name";
	HitPoint = FragTrap::getHP();
	EnergyPoints = ScavTrap::getEP();
	AttackDamage = FragTrap::getAD();
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string _name) : ClapTrap(_name + "_ClapTrap"), ScavTrap(_name), FragTrap(_name)
{
	std::cout << "DiamondTrap Constructor with param called" << std::endl;
	this->Name = _name;
	HitPoint = FragTrap::getHP();
	EnergyPoints = ScavTrap::getEP();
	AttackDamage = FragTrap::getAD();
}

DiamondTrap::DiamondTrap(const DiamondTrap& _copy) : ClapTrap(_copy), ScavTrap(_copy), FragTrap(_copy) 
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = _copy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& _assignment)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &_assignment)
	{
		Name = _assignment.Name;
		ClapTrap::Name = _assignment.ClapTrap::Name;
		HitPoint = _assignment.HitPoint;
		EnergyPoints = _assignment.EnergyPoints;
		AttackDamage = _assignment.AttackDamage;
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I'm " << Name << " My ClapTrap name is: " << ClapTrap::Name << std::endl;
}
