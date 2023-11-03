/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:06:25 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/31 13:16:36 by kchaouki         ###   ########.fr       */
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


typedef struct s_vectorDataHolder
{
	VectorOfPairs vectorOfPairs;
	std::vector<unsigned int> mainContainer;
} t_vectorDataHolder;

int	numberOfCmpVec;

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

	numberOfCmpVec++;
	if (pair.first[0] > pair.second[0])
	{
		tmp = pair.first[0];
		pair.first[0] = pair.second[0];
		pair.second[0] = tmp;
	}
}

void	pairToSingleVector(std::vector<unsigned int>& vec, PairVec pair)
{
	for (size_t i = 0; i < pair.first.size(); i++)
		vec.push_back(pair.first[i]);
	for (size_t i = 0; i < pair.second.size(); i++)
		vec.push_back(pair.second[i]);
}

void	fillMainAndPendChain(VectorOfVectors& mainChain, VectorOfVectors& pend, VectorOfPairs vectorOfPairs)
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

		// if (i == 0)
		// {
		// 	mainChain.push_back(firstPair.first);
		// 	mainChain.push_back(firstPair.second);
		// 	mainChain.push_back(secondPair.second);
		// 	pend.push_back(secondPair.first);
		// 	continue ;
		// }
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
	numberOfCmpVec++;
	return (subVec.back() <= target);
}

void	createPairs(t_vectorDataHolder& data, std::vector<unsigned int>& rest)
{
	std::vector<unsigned int> first;
	std::vector<unsigned int> second;
	size_t leftSize = data.mainContainer.size();
	size_t i = 0;

	leftSize = (leftSize % 2 == 0) ? leftSize : leftSize - 1;
	for (; i < leftSize; i += 2)
	{
		first.push_back(data.mainContainer[i]);
		second.push_back(data.mainContainer[i + 1]);
		data.vectorOfPairs.push_back(std::make_pair(first, second));
		first.clear();
		second.clear();
	}
	rest.push_back(data.mainContainer[i]);
	data.mainContainer.clear();
	for (size_t i = 0; i < data.vectorOfPairs.size(); i++)
		sortPair(data.vectorOfPairs[i]);
}

unsigned int jacobsthal(unsigned int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * (jacobsthal(n - 2)));
}

std::vector<unsigned int> createJacobsthalSequence(unsigned int pendSize)
{
	std::vector<unsigned int> sequence;
	unsigned int index = 3;

	while (jacobsthal(index) < pendSize)
	{
		sequence.push_back(jacobsthal(index));
		index++;
	}
	return (sequence);
}

void	mergeInsertionUsingVector(t_vectorDataHolder& data)
{
	VectorOfVectors mainChain; 
	VectorOfVectors pend;
	std::vector<unsigned int> rest;
	size_t	actualSize = data.vectorOfPairs.size();

	if (actualSize == 0)
		createPairs(data, rest);
	else
	{
		size_t i = 0;
		
		size_t vectorOfPairSize = (actualSize % 2 == 0 ? actualSize : actualSize - 1);
		for (; i < vectorOfPairSize; i += 2)
		{
			std::vector<unsigned int> first;
			std::vector<unsigned int> second;
			pairToSingleVector(first, data.vectorOfPairs[i]);
			pairToSingleVector(second, data.vectorOfPairs[i + 1]);
			numberOfCmpVec++;
			if (first[first.size() - 1] > second[first.size() - 1])
				data.vectorOfPairs.push_back(std::make_pair(second, first));
			else
				data.vectorOfPairs.push_back(std::make_pair(first, second));
		}
		if (actualSize % 2 != 0)
			pairToSingleVector(rest, data.vectorOfPairs[i]);
		data.vectorOfPairs.erase(data.vectorOfPairs.begin(), data.vectorOfPairs.begin() + actualSize);
	}

	//print--------------
	// std::cout << "########################################################\n";
	// std::cout << "recurtion depth: " << depth << std::endl; 
	// std::cout << "number of comparaisons: " << numberOfCmpVec std::endl; 
	// std::cout << "vectorOfPairs size: " << data.vectorOfPairs.size() << std::endl;
	// printVectorPair(data);
	// std::cout << "rest: ";
	// printSimpleVector(rest);
	// if (depth == 1)
	// 	return ;
	// if (data.vectorOfPairs.size() <= 1)
	// 	return ;
	if (data.vectorOfPairs.size() > 1)
		mergeInsertionUsingVector(data);
	// if (depth == 3)
	// 	return ;
	// exit (1);
	// std::cout << "########################################################\n";
	// std::cout << "reverse recurtion depth: " << depth << std::endl;
	// std::cout << "number of comparaisons: " << numberOfCmpVec std::endl; 
	// std::cout << "vectorOfPairs size: " << data.vectorOfPairs.size() << std::endl;
	printVectorPair(data);
	fillMainAndPendChain(mainChain, pend, data.vectorOfPairs);

	//print--------------
	// std::cout << "mainChain: ";
	// printVectorOfVectors(mainChain);
	// std::cout << "pend: ";
	// printVectorOfVectors(pend);
	// std::cout << "rest: ";
	// printSimpleVector(rest);

	//	push rest to pend
	if (rest.size())
		pend.push_back(rest);
	// std::cout << "pend after inserting rest: ";
	// printVectorOfVectors(pend);
	//inset pend to the mainChain
	size_t	pendSize = pend.size();
	std::vector<unsigned int> sequence = createJacobsthalSequence(pendSize + 1);
	// std::cout << "jacob numbers: ";
	// printSimpleVector(sequence);
	size_t	pos;
	size_t	added = 1;
	size_t	lastEndp = 1;
	if (pend.size())
		mainChain.insert(mainChain.begin(), pend[0]);
	for (size_t i = 0; i < sequence.size(); i++)
	{
		pos = sequence[i];
		VectorOfVectors::iterator it;
		unsigned int target;
		// std::cout << "mainChain befor: ";
		// printVectorOfVectors(mainChain);
		while (lastEndp < pos)
		{
			// std::cout << "pos: " << pos << std::endl;
			// std::cout << "added: " << added << std::endl;
			target = pend[pos - 1].back();
			it = std::lower_bound(mainChain.begin(), mainChain.begin() + (pos - 1) + added, target, customComparator);
			mainChain.insert(it, pend[pos - 1]);
			// std::cout << "mainChain: ";
			// printVectorOfVectors(mainChain);
			pos--;
			added++;
		}
		lastEndp = sequence[i];
	}
	// if (depth == 2)	
	// 	exit(1);
	// for (size_t i = 0; i < pend.size(); i++)
	// {
	// 	VectorOfVectors::iterator it;
	// 	unsigned int target = pend[i].back();
	// 	// if(i == 0 && mainChain.size() > 2)
	// 	// 	it = std::lower_bound(mainChain.begin(), mainChain.begin() + 2, target, customComparator);
	// 	// else
	// 		it = std::lower_bound(mainChain.begin(), mainChain.end(), target, customComparator);
	// 	mainChain.insert(it, pend[i]);	
	// }
	// }

	pend.clear();

	// inset rest to the mainChain
	// if (rest.size() > 0)
	// {
	// 	unsigned int target = rest.back();
	// 	VectorOfVectors::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), target, customComparator);
	// 	mainChain.insert(it, rest);
	// }
	// rest.clear();

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

	//push the final result to the mainContainer 
	if (mainChain[0].size() == 1)
	{
		for (size_t i = 0;i < mainChain.size();i++)
			data.mainContainer.push_back(mainChain[i][0]);
	}
	return ;
}















// sorting using list
typedef std::pair<std::list<unsigned int>, std::list<unsigned int> > PairList;
typedef std::list<PairVec > ListOfPairs;
typedef std::list<std::list<unsigned int> > ListOfLists;
typedef std::list<unsigned int>::iterator list_Iter;
typedef std::list<PairVec >::iterator ListOfPairs_Iter;
typedef std::list<std::list<unsigned int> >::iterator ListOfLists_iter;

typedef struct s_listDataHolder
{
	ListOfPairs listOfPairs;
	std::list<unsigned int> mainContainer;
} t_listDataHolder;


int	numberOfCmpList = 0;

void	createPairs(t_listDataHolder& data, std::list<unsigned int>& rest)
{
	std::list<unsigned int> first;
	std::list<unsigned int> second;
	size_t listSize = data.mainContainer.size();
	size_t i = 0;

	listSize = (listSize % 2 == 0) ? listSize : listSize - 1;
	list_Iter itBegin = data.mainContainer.begin();
	list_Iter itEnd = data.mainContainer.end();
	while (i < listSize && itBegin != itEnd)
	{
		first.push_back(*itBegin);
		itBegin++;
		second.push_back(*itBegin);
		itBegin++;
		// data.listOfPairs.push_back(std::make_pair(first, second));
		first.clear();
		second.clear();
		i += 2;
	}
	// for (; i < leftSize; i += 2)
	// {
	// 	first.push_back(data.mainContainer[i]);
	// 	second.push_back(data.mainContainer[i + 1]);
	// 	data.vectorOfPairs.push_back(std::make_pair(first, second));
	// 	first.clear();
	// 	second.clear();
	// }
	// rest.insert();
	// first.push_back(*itBegin);
	// if (data.mainContainer.size() % 2 != 0)
	// 	pairToSingleVector(rest, std::make_pair(first, second));
	data.mainContainer.clear();
	// for (size_t i = 0; i < data.vectorOfPairs.size(); i++)
	// 	sortPair(data.vectorOfPairs[i]);
}


void	mergeInsertionUsingList(int depth, t_listDataHolder& data)
{
	ListOfLists mainChain; 
	ListOfLists pend;
	std::list<unsigned int> rest;

	if (data.listOfPairs.size() == 0)
		createPairs(data, rest);
	// if (data.listOfPairs.size() > 1)
	// 	mergeInsertionUsingList(depth + 1, data);
}

std::list<unsigned int>	vectorToList(std::vector<unsigned int> parsed)
{
	std::list<unsigned int> list;
	for (size_t i = 0; i < parsed.size();i++)
		list.push_back(parsed[i]);
	return (list);
}

void	PmergeMe(int ac, char** args)
{
	t_vectorDataHolder	vecDataHolder;
	t_listDataHolder	listDataHolder;
	std::vector<unsigned int> numbers;
	vecDataHolder.mainContainer = parseArguments(ac, args);
	listDataHolder.mainContainer = vectorToList(vecDataHolder.mainContainer);
	std::cout << "Before: ";
	for (size_t i = 0; i < vecDataHolder.mainContainer.size();i++)
		std::cout << vecDataHolder.mainContainer[i] << " ";
	std::cout << std::endl;
	std::cout << "========================================================" << std::endl;
	mergeInsertionUsingVector(vecDataHolder);
	// numbers = dataHolder.mainContainer;
	std::cout << "========================================================" << std::endl;
	std::cout << "After: ";
	for (size_t i = 0; i < vecDataHolder.mainContainer.size();i++)
		std::cout << vecDataHolder.mainContainer[i] << " ";
	std::cout << std::endl;
	std::cout << "Number of comparaison for vector: " << numberOfCmpVec << std::endl;



	// std::cout << "Before: ";
	// for (list_Iter it = listDataHolder.mainContainer.begin(); it != listDataHolder.mainContainer.end();it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// std::cout << "========================================================" << std::endl;
	// mergeInsertionUsingList(0, listDataHolder);
	// std::cout << "========================================================" << std::endl;
	// std::cout << "After: ";
	// for (list_Iter it = listDataHolder.mainContainer.begin(); it != listDataHolder.mainContainer.end();it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// std::cout << "Number of comparaison for list: " << numberOfCmpList << std::endl;

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

// 7 10 11 4 9 10 12 4 18 11 9 2 18 16 9 18