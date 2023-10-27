/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:06:25 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/27 18:07:36 by kchaouki         ###   ########.fr       */
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
			throw std::invalid_argument("Error: Invalid argument\n\tEnter numbers only");
		nbr = strtol(args[i], NULL, 10);
		if (nbr < 0)
			throw std::invalid_argument("Error: Invalid argument\n\tEnter positive numbers only");
		numbers.push_back(nbr);
		i++;
	}
	// std::cout << "PmergeMe: " << args[1] << std::endl;
	return (numbers);
}

typedef std::pair<std::vector<unsigned int>, std::vector<unsigned int> > pairVec;
typedef std::vector<pairVec > VectorPair;

typedef struct s_dataHolder
{
	VectorPair vectorOfPairs;
	std::vector<unsigned int> left;
} t_dataHolder;

void	printVectorPair(t_dataHolder data)
{
	std::cout << "left: ";
	for (size_t i = 0; i < data.left.size(); i++)
	{
		std::cout << data.left[i];
		if (i < data.left.size() - 1)
			std::cout << " ";		
	}
	std::cout << std::endl;
	std::cout << "vectorPair: ";
	for (size_t i = 0; i < data.vectorOfPairs.size(); i++)
	{
		pairVec pairData = data.vectorOfPairs[i];
		std::vector<unsigned int> vFisrt = pairData.first;
		std::vector<unsigned int> vSecond = pairData.second;
		
		std::cout << "{";
		for (size_t j = 0; j < vFisrt.size(); j++)
		{
			std::cout << vFisrt[j];
			if (j < vFisrt.size() - 1)
				std::cout << " ";
		}
		std::cout << "}";
		std::cout << ",{";
		for (size_t j = 0; j < vSecond.size(); j++)
		{
			std::cout << vSecond[j];
			if (j < vSecond.size() - 1)
				std::cout << " ";
		}
		std::cout << "}";

	}
	std::cout << std::endl;
}

void	makePair(pairVec& pair, std::vector<unsigned int> vec)
{
	std::vector<unsigned int> first;
	std::vector<unsigned int> second;

	size_t leftSize = vec.size();
	if (leftSize % 2 != 0)
		leftSize--;
	for (size_t i = 0; i < leftSize;i++)
	{
		if (i < leftSize / 2)
			first.push_back(vec[i]);
		else
			second.push_back(vec[i]);
	}
	pair = std::make_pair(first, second);
}

void	sortPair(pairVec& pair)
{
	unsigned int tmp;

	// std::cout << "first: " << pair.first[0] << " second: " << pair.second[0] << std::endl;
	if (pair.first[0] > pair.second[0])
	{
		tmp = pair.first[0];
		pair.first[0] = pair.second[0];
		pair.second[0] = tmp;
	}
}

void	mergeInsertion(t_dataHolder& data)
{
	if (data.vectorOfPairs.size() == 0)
	{
		pairVec pair;
		makePair(pair, data.left);
		if (data.left.size() % 2 != 0)
			data.left.erase(data.left.begin(), data.left.end() - 1);
		else
			data.left.erase(data.left.begin(), data.left.end());
		data.vectorOfPairs.push_back(pair);
	}
	size_t	vectorOfPairSize = data.vectorOfPairs.size();
	for (size_t i = 0; i < vectorOfPairSize; i++)
	{
		pairVec pair;
		makePair(pair, data.vectorOfPairs[i].first);
		data.vectorOfPairs.push_back(pair);
		makePair(pair, data.vectorOfPairs[i].second);
		data.vectorOfPairs.push_back(pair);
	}
	data.vectorOfPairs.erase(data.vectorOfPairs.begin(), data.vectorOfPairs.begin() + vectorOfPairSize);
	std::cout << "vector size = "<< data.vectorOfPairs[0].first.size() << std::endl;
	if (data.vectorOfPairs[0].first.size() > 1)
		mergeInsertion(data);
	for (size_t i = 0; i < data.vectorOfPairs.size(); i++)
		sortPair(data.vectorOfPairs[i]);
	printVectorPair(data);
	exit (1);
	return ;
}

void	PmergeMe(int ac, char** args)
{
	std::vector<unsigned int> numbers;
	numbers = parseArguments(ac, args);
	std::cout << "Before: ";
	for (size_t i = 0; i < numbers.size();i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;
	std::cout << "------------------------------------" << std::endl;
	t_dataHolder dataHolder;
	dataHolder.left = numbers;
	mergeInsertion(dataHolder);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "After: ";
	for (size_t i = 0; i < numbers.size();i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;
	return ;
}

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		try
		{
			PmergeMe(ac, av);
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