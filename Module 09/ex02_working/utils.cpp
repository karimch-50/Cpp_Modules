/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:54:54 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/11 20:58:38 by kchaouki         ###   ########.fr       */
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

void	printSimpleList(std::list<unsigned int> list)
{
	for (list_Iter it = list.begin(); it != list.end();)
	{
		std::cout << *it;
		if (++it != list.end())
			std::cout << " ";
	}
}

void	printListOfList(ListOfLists lOfl)
{
	for (listOfLists_Iter it = lOfl.begin(); it != lOfl.end();)
	{
		printSimpleList(*it);
		if (++it != lOfl.end())
			std::cout << " , ";
	}
	std::cout << std::endl;
}

void	printPair(PairList pairData)
{
	std::cout << "Pair data: [";
	printSimpleList(pairData.first);
	std::cout << ", ";
	printSimpleList(pairData.second);
	std::cout << "]" << std::endl;
}

void	printListPair(t_listDataHolder data)
{
	std::cout << "ListPairs: ";
	for (listOfPairs_Iter it = data.listOfPairs.begin(); it != data.listOfPairs.end();it++)
	{
		std::cout << "{";
		printSimpleList((*it).first);
		std::cout << ", ";
		printSimpleList((*it).second);
		std::cout << "}";

	}
	std::cout << std::endl;
}
