/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:20:14 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/07 12:20:25 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public	ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(const std::string _name);
		ScavTrap(const ScavTrap& _copy);
		ScavTrap& operator=(const ScavTrap& _assignment);
		void attack(const std::string& target);
		void guardGate();
		int	getHP();
		int getEP();
		int getAD();
};


#endif