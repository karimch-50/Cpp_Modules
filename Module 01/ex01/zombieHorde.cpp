/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 08:57:06 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/24 13:19:25 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int	i;

	i = -1;
	if (N > 0)
	{
		Zombie* zombie = new Zombie[N];
		while (++i < N)
			zombie[i].setName(name);
		return (zombie);
	}
	return (NULL);
}
