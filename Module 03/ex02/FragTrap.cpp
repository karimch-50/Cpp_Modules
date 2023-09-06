/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:37:07 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/06 19:09:49 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	Name = "Unknown";
	HitPoint = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(std::string _name):ClapTrap(_name)
{
	std::cout << "FragTrap Constructor with param called" << std::endl;
	HitPoint = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
}

FragTrap::FragTrap(const FragTrap& _copy):ClapTrap(_copy)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = _copy;
}

FragTrap& FragTrap::operator=(const FragTrap& _assignment)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &_assignment)
	{
		Name = _assignment.Name;
		HitPoint = _assignment.HitPoint;
		EnergyPoints = _assignment.EnergyPoints;
		AttackDamage = _assignment.AttackDamage;
	}
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "🖐🏻" << std::endl;
}
