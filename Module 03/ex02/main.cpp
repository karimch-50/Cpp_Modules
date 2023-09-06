/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:41:55 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/06 13:03:37 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavTrap("karim");

	scavTrap.attack("chiwa7d");
	scavTrap.takeDamage(12);
	scavTrap.guardGate();
	return (0);
}