/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:24:05 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/07 12:20:05 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIANONDTRAP_HPP
#define DIANONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string Name;
	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(const std::string _name);
		DiamondTrap(const DiamondTrap& _copy);
		DiamondTrap& operator=(const DiamondTrap& _assignment);
		void attack(const std::string& target);
		void whoAmI();
};

#endif