/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 08:57:09 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/22 14:09:00 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombie = zombieHorde(3, "test");
	for (int i = 0; i < 3; i++)
		zombie[i].announce();

	delete [] zombie;
	// std::cout << "heeer\n";
	return (0);
}