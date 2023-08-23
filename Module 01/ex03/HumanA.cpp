/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:43:26 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/23 13:12:53 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon& _weapon) : weapon(_weapon)
{
	name = _name;
}

void	HumanA::setWeapon(Weapon& _weapon)
{
	weapon = _weapon;
}

void	HumanA::attack(void)
{
	std::cout << name << "  attacks with their " << weapon.getType() << std::endl;
}
