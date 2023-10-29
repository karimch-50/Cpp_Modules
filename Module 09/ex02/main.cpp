/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:06:25 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/29 16:15:05 by kchaouki         ###   ########.fr       */
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
	return (numbers);
}

typedef std::pair<std::vector<unsigned int>, std::vector<unsigned int> > PairVec;
typedef std::vector<PairVec > VectorOfPairs;
typedef std::vector<std::vector<unsigned int> > VectorOfVectors;


typedef struct s_dataHolder
{
	VectorOfPairs vectorOfPairs;
	std::vector<unsigned int> left;
} t_dataHolder;

int	numberOfCmp = 0;

void	printVectorPair(t_dataHolder data)
{
	std::cout << "vectorPair: ";
	for (size_t i = 0; i < data.vectorOfPairs.size(); i++)
	{
		PairVec pairData = data.vectorOfPairs[i];
		std::vector<unsigned int> vFisrt = pairData.first;
		std::vector<unsigned int> vSecond = pairData.second;
		
		std::cout << "{";
		for (size_t j = 0; j < vFisrt.size(); j++)
		{
			std::cout << vFisrt[j];
			if (j < vFisrt.size() - 1)
				std::cout << " ";
		}
		std::cout << ", ";
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

void	printVectorOfVectors(VectorOfVectors vOfv)
{
	for (size_t i = 0; i < vOfv.size();i++)
	{
		for (size_t j = 0; j < vOfv[i].size(); j++)
		{
			std::cout << vOfv[i][j] ;
			if (j < vOfv[i].size() - 1)
				std::cout << " ";
		}
		if (i < vOfv.size() - 1)
			std::cout << " , ";
	}
	std::cout << std::endl;
}

void	printPair(PairVec pairData)
{
	std::cout << "Pair data: [";
	for (size_t i = 0; i < pairData.first.size(); i++)
	{
		std::cout << pairData.first[i];
		if (i < pairData.first.size() - 1)
			std::cout << " ";	
	}
	std::cout << ", ";
	for (size_t i = 0; i < pairData.second.size(); i++)
	{
		std::cout << pairData.second[i];
		if (i < pairData.second.size() - 1)
			std::cout << " ";	
	}
	std::cout << "]" << std::endl;
}

void	printSimpleVector(std::vector<unsigned int> vec)
{
	for (size_t i = 0; i < vec.size();i++)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << " ";	
	}
	std::cout << std::endl;
}

void	makePair(PairVec& pair, std::vector<unsigned int> vec)
{
	std::vector<unsigned int> first;
	std::vector<unsigned int> second;

	size_t leftSize = vec.size();
	leftSize = (leftSize % 2 == 0) ? leftSize : leftSize - 1;
	for (size_t i = 0; i < leftSize;i++)
	{
		if (i < leftSize / 2)
			first.push_back(vec[i]);
		else
			second.push_back(vec[i]);
	}
	pair = std::make_pair(first, second);
}

void	sortPair(PairVec& pair)
{
	unsigned int tmp;

	numberOfCmp++;
	if (pair.first[0] > pair.second[0])
	{
		tmp = pair.first[0];
		pair.first[0] = pair.second[0];
		pair.second[0] = tmp;
	}
}

void	pairTwoSingleVector(std::vector<unsigned int>& vec, PairVec pair)
{
	for (size_t i = 0; i < pair.first.size(); i++)
		vec.push_back(pair.first[i]);
	for (size_t i = 0; i < pair.second.size(); i++)
		vec.push_back(pair.second[i]);
}

void	pushToRest(std::vector<unsigned int>& rest, PairVec pair)
{
	for (size_t i = 0; i < pair.first.size(); i++)
		rest.push_back(pair.first[i]);
	for (size_t i = 0; i < pair.second.size(); i++)
		rest.push_back(pair.second[i]);
}

void	fillMainAndPendChain(VectorOfVectors& mainChain, VectorOfVectors& pend, VectorOfPairs vectorOfPairs, int depth)
{
	size_t	originalSize = vectorOfPairs.size();
	size_t	sizeOfVectorOfPairs = (originalSize % 2 == 0 ? originalSize : originalSize - 1);
	size_t i = 0;
	if (originalSize == 1)
	{
		mainChain.push_back(vectorOfPairs[0].first);
		mainChain.push_back(vectorOfPairs[0].second);
		return ;
	}
	for (; i < sizeOfVectorOfPairs; i += 2)
	{
		PairVec firstPair = vectorOfPairs[i];
      PairVec secondPair = vectorOfPairs[i + 1];

		if (i == 0)
		{
			mainChain.push_back(firstPair.first);
			mainChain.push_back(firstPair.second);
			mainChain.push_back(secondPair.second);
			pend.push_back(secondPair.first);
			continue ;
		}
		mainChain.push_back(firstPair.second);
		mainChain.push_back(secondPair.second);
		pend.push_back(firstPair.first);
		pend.push_back(secondPair.first);
	}
	if (originalSize % 2 != 0)
	{
		mainChain.push_back(vectorOfPairs[i].second);
		pend.push_back(vectorOfPairs[i].first);
	}
}

bool	customComparator(std::vector<unsigned int> subVec, int target)
{
	numberOfCmp++;
	return (subVec.back() <= target);
}

void	pushBackToLeft(VectorOfVectors mainChain, std::vector<unsigned int>& left)
{
	for (size_t i = 0;i < mainChain.size();i++)
		left.push_back(mainChain[i][0]);
}

void	mergeInsertion(int depth, t_dataHolder& data)
{
	VectorOfVectors mainChain; 
	VectorOfVectors pend;
	std::vector<unsigned int> rest;

	if (data.vectorOfPairs.size() == 0)
	{
		std::vector<unsigned int> first;
		std::vector<unsigned int> second;
		size_t leftSize = data.left.size();
		size_t i = 0;

		leftSize = (leftSize % 2 == 0) ? leftSize : leftSize - 1;
		for (; i < leftSize; i += 2)
		{
			first.push_back(data.left[i]);
			second.push_back(data.left[i + 1]);
			data.vectorOfPairs.push_back(std::make_pair(first, second));
			first.clear();
			second.clear();
		}
		first.push_back(data.left[i]);
		if (data.left.size() % 2 != 0)
			pushToRest(rest, std::make_pair(first, second));
		data.left.erase(data.left.begin(), data.left.end());
		for (size_t i = 0; i < data.vectorOfPairs.size(); i++)
			sortPair(data.vectorOfPairs[i]);
	}
	else
	{
		size_t	actualSize = data.vectorOfPairs.size();
		size_t i = 0;
		
		size_t vectorOfPairSize = (actualSize % 2 == 0 ? actualSize : actualSize - 1);
		for (; i < vectorOfPairSize; i += 2)
		{
			std::vector<unsigned int> first;
			std::vector<unsigned int> second;
			pairTwoSingleVector(first, data.vectorOfPairs[i]);
			pairTwoSingleVector(second, data.vectorOfPairs[i + 1]);
			numberOfCmp++;
			if (first[first.size() - 1] > second[first.size() - 1])
				data.vectorOfPairs.push_back(std::make_pair(second, first));
			else
				data.vectorOfPairs.push_back(std::make_pair(first, second));
		}
		if (actualSize % 2 != 0)
			pushToRest(rest, data.vectorOfPairs[i]);
		data.vectorOfPairs.erase(data.vectorOfPairs.begin(), data.vectorOfPairs.begin() + actualSize);
	}

	//print--------------
	// std::cout << "########################################################\n";
	// std::cout << "number of comparaisons: " << numberOfCmp << std::endl; 
	// std::cout << "recurtion depth: " << depth << std::endl; 
	// std::cout << "vectorOfPairs size: " << data.vectorOfPairs.size() << std::endl;
	// printVectorPair(data);
	// std::cout << "rest: ";
	// printSimpleVector(rest);
	// if (depth == 1)
	// 	return ;
	// if (data.vectorOfPairs.size() <= 1)
	// 	return ;
	if (data.vectorOfPairs.size() > 1)
		mergeInsertion(depth + 1, data);
	// if (depth == 3)
	// 	return ;
	// exit (1);
	// std::cout << "########################################################\n";
	// std::cout << "reverse recurtion depth: " << depth << std::endl;
	// std::cout << "number of comparaisons: " << numberOfCmp << std::endl; 
	// std::cout << "vectorOfPairs size: " << data.vectorOfPairs.size() << std::endl;
	// printVectorPair(data);
	fillMainAndPendChain(mainChain, pend, data.vectorOfPairs, depth);

	//print--------------
	// std::cout << "mainChain: ";
	// printVectorOfVectors(mainChain);
	// std::cout << "pend: ";
	// printVectorOfVectors(pend);
	// std::cout << "rest: ";
	// printSimpleVector(rest);

	//inset pend to the mainChain
	for (size_t i = 0; i < pend.size(); i++)
	{
		VectorOfVectors::iterator it;
		unsigned int target = pend[i].back();
		if(i == 0 && mainChain.size() > 2)
			it = std::lower_bound(mainChain.begin(), mainChain.begin() + 2, target, customComparator);
		else
			it = std::lower_bound(mainChain.begin(), mainChain.end(), target, customComparator);
		mainChain.insert(it, pend[i]);	
	}
	pend.clear();

	// inset rest to the mainChain
	if (rest.size() > 0)
	{
		unsigned int target = rest.back();
		VectorOfVectors::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), target, customComparator);
		mainChain.insert(it, rest);
	}
	rest.clear();

	//print--------------
	// std::cout << "Final mainChain: ";
	// printVectorOfVectors(mainChain);
	// std::cout << "Final pend: ";
	// printVectorOfVectors(pend);
	// std::cout << "Final rest: ";
	// printSimpleVector(rest);
	// printVectorPair(data);
	
	//make pairs again and fill the vector of pairs
	data.vectorOfPairs.clear();
	for (size_t i = 0;i < mainChain.size(); i++)
	{
		PairVec pairOfVec;
		makePair(pairOfVec, mainChain[i]);
		data.vectorOfPairs.push_back(pairOfVec);
	}
	
	// std::cout << "MainChain: ";
	// printVectorOfVectors(mainChain);
	if (mainChain[0].size() == 1)
		pushBackToLeft(mainChain, data.left);
	mainChain.clear();
	// if (depth == 1)
	// 	exit (1);
	return ;
}

void	PmergeMe(int ac, char** args)
{
	t_dataHolder dataHolder;
	std::vector<unsigned int> numbers;
	dataHolder.left = parseArguments(ac, args);
	std::cout << "Before: ";
	for (size_t i = 0; i < dataHolder.left.size();i++)
		std::cout << dataHolder.left[i] << " ";
	std::cout << std::endl;
	std::cout << "------------------------------------" << std::endl;
	mergeInsertion(0, dataHolder);
	// numbers = dataHolder.left;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "After: ";
	for (size_t i = 0; i < dataHolder.left.size();i++)
		std::cout << dataHolder.left[i] << " ";
	std::cout << std::endl;
	std::cout << "Number of comparaison: " << numberOfCmp << std::endl;
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