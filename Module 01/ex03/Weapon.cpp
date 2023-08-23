/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:43:08 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/23 13:24:25 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	
}

Weapon::Weapon(std::string _type)
{
	type = _type;
}

void	Weapon::setType(std::string _type)
{
	type = _type;
}

const std::string&	Weapon::getType(void)
{
	return (type);
}
