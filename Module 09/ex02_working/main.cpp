/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:06:25 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/11 01:16:51 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	checkArgument(char *arg)
{
	int i = 0;
	while (arg[i])
	{
		if (!std::isdigit(arg[i]))
			return (false);
		i++;
	}
	return (true);
}

std::vector<unsigned int>	parseArguments(int ac, char **args)
{
	std::vector<unsigned int> numbers;
	int	nbr;
	int	i = 1;
	while (i < ac)
	{
		if(!checkArgument(args[i]))
			throw std::invalid_argument("Error: Invalid argument\n\tEnter positive numbers only");
		nbr = strtol(args[i], NULL, 10);
		numbers.push_back(nbr);
		i++;
	}
	return (numbers);
}

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		try
		{
			PmergeMe(parseArguments(ac, av));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
		std::cout << "Usage: \n\t./PmergeMe <nbr1> <nbr2> <nbr3> ..." << std::endl;
	return (0);
}
