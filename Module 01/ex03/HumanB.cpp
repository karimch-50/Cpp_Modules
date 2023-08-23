/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:43:20 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/23 13:38:10 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string _name)
{
	weapon = NULL;
	name = _name;
}

void	HumanB::setWeapon(Weapon& _weapon)
{
	weapon = &_weapon;
}

void	HumanB::attack(void)
{
	if (weapon)
		std::cout << name << "  attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " ma3endoch slaa7" << std::endl;
}
