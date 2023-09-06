/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:41:55 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/06 12:32:11 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap1("karim");
	ClapTrap clapTrap2("3ebaas");

	clapTrap1.attack("3ebass");
	clapTrap1.takeDamage(1);
	clapTrap1.beRepaired(2);
	
	return (0);
}
