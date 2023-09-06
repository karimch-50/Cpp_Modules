/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:41:57 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/06 18:49:47 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string Name;
		int			HitPoint;
		int			EnergyPoints;
		int			AttackDamage;
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap& _copy);
		ClapTrap& operator=(const ClapTrap& _assignment);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif