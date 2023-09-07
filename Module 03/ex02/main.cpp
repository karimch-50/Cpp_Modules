/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:41:55 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/07 12:24:40 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap scavTrap("karim");
	FragTrap fragTrap("karim");

	scavTrap.attack("chiwa7d");
	scavTrap.takeDamage(12);
	scavTrap.guardGate();
	fragTrap.attack("chiwa7d");
	fragTrap.takeDamage(12);
	fragTrap.highFivesGuys();
	return (0);
}