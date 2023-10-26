/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:06:25 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/26 18:31:25 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	checkArgument(char *arg)
{
	int i = 0;
	while (arg[i])
	{
		// remove check for - i'll check it after this function
		if (!std::isdigit(arg[i]))
			return (std::cout << "Error: Invalid argument\n\tEnter numbers only" << std::endl, false);
		i++;
	}
	return (true);
}

int	PmergeMe(int ac, char** args)
{
	std::vector<int> numbers;
	int	nbr;
	int	i = 1;
	while (i < ac)
	{
		if(checkArgument(args[i]))
			return (1);
		nbr = strtol(args[i], NULL, 10);
		if (nbr < 0)
			return (std::cout << "Error: Invalid argument\n\tEnter positive numbers only" , 1);
		numbers.push_back(nbr);
		i++;
	}
	std::cout << "PmergeMe: " << args[1] << std::endl;
	return (0);
}

int main(int ac, char **av)
{
	if (ac >= 2)
		return (PmergeMe(ac, av));
	else
		std::cout << "Usage: \n\t./PmergeMe <nbr1> <nbr2> <nbr3> ..." << std::endl;
	return (0);
}