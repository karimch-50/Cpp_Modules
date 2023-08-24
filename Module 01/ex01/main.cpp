/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 08:57:09 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/24 13:20:14 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 10;
	Zombie *zombie = zombieHorde(N, "test");
	for (int i = 0; i < N; i++ && zombie)
		zombie[i].announce();
	delete [] zombie;
	return (0);
}