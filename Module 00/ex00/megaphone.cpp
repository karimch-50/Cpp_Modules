/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:53:05 by kchaouki          #+#    #+#             */
/*   Updated: 2023/07/09 21:25:35 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if (ac >= 2)
	{
		i = 1;	
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				if (av[i][j] >= 'a' && av[i][j] <= 'z')
					std::cout << (char) (av[i][j] - 32);
				else
					std::cout << av[i][j];
				j++;
			}
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}