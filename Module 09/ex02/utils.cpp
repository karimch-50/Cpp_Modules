/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:54:54 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/03 12:03:25 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printVectorPair(t_vectorDataHolder data)
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
