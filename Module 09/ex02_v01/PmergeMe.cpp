/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:06:30 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/09 11:26:04 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

/*============>sorting using vector<============*/
int	numberOfCmpVec;

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

bool	customComparator(std::vector<unsigned int> subVec, unsigned int target)
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

void	mergeInsertionUsingVector(t_vectorDataHolder& data)
{
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

	if (data.vectorOfPairs.size() > 1)
		mergeInsertionUsingVector(data);

	//	push rest to pend
	if (rest.size())
		pend.push_back(rest);

	if (data.mainChain.size() == 0)
		fillMainAndPendChain(data, pend);
	else
		


	size_t	pendSize = pend.size();
	std::vector<unsigned int> sequence = createJacobsthalSequence(pendSize + 1);

	//insert to first elem of pend to the mainChain
	if (pendSize)
		mainChain.insert(mainChain.begin(), pend[0]);

	size_t	pos;
	size_t	added = 1;
	size_t	lastEndp = 1;
	//start inseting elements of the pend to the mainChain using Jacob Sequence
	for (size_t i = 0; i < sequence.size(); i++)
	{
		pos = sequence[i];
		VectorOfVectors::iterator it;
		unsigned int target;
		while (lastEndp < pos)
		{
			target = pend[pos - 1].back();
			it = std::lower_bound(mainChain.begin(), mainChain.begin() + (pos - 1) + added, target, customComparator);
			mainChain.insert(it, pend[pos - 1]);
			pos--;
			added++;
		}
		lastEndp = sequence[i];
	}
	pend.clear();

	//make pairs again and fill the vector of pairs
	// data.vectorOfPairs.clear();
	// for (size_t i = 0;i < mainChain.size(); i++)
	// {
	// 	PairVec pairOfVec;
	// 	makePair(pairOfVec, mainChain[i]);
	// 	data.vectorOfPairs.push_back(pairOfVec);
	// }

	//push the final result to the mainContainer 
	// if (mainChain[0].size() == 1)
	// {
	// 	for (size_t i = 0;i < mainChain.size();i++)
	// 		data.mainContainer.push_back(mainChain[i][0]);
	// }
	return ;
}

/*============>sorting using list<============*/
int	numberOfCmpList = 0;

void	sortPair(PairList& pair)
{
	unsigned int tmp;

	numberOfCmpList++;
	if (pair.first.back() > pair.second.back())
	{
		tmp = pair.first.back();
		pair.first.back() = pair.second.back();
		pair.second.back() = tmp;
	}
}

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
		data.listOfPairs.push_back(std::make_pair(first, second));
		first.clear();
		second.clear();
		i += 2;
	}
	rest.push_back(*itBegin);
	data.mainContainer.clear();
	for (listOfPairs_Iter it = data.listOfPairs.begin(); it != data.listOfPairs.end();it++)
		sortPair(*it);
}

void	pairToSingleList(std::list<unsigned int>& vec, PairList pair)
{
	for (list_Iter it = pair.first.begin(); it != pair.first.end();it++)
		vec.push_back(*it);
	for (list_Iter it = pair.second.begin(); it != pair.second.end();it++)
		vec.push_back(*it);
}

void	fillMainAndPendChain(ListOfLists& mainChain, ListOfLists& pend, ListOfPairs listOfPairs)
{
	size_t	originalSize = listOfPairs.size();
	size_t	sizeOfListOfPairs = (originalSize % 2 == 0 ? originalSize : originalSize - 1);
	listOfPairs_Iter itBegin = listOfPairs.begin();
	if (originalSize == 1)
	{
		mainChain.push_back((*itBegin).first);
		mainChain.push_back((*itBegin).second);
		return ;
	}
	for (size_t i = 0; i < sizeOfListOfPairs && itBegin != listOfPairs.end(); i += 2)
	{
		PairList firstPair = *itBegin;
		itBegin++;
    	PairList secondPair = *itBegin;
		itBegin++;
		mainChain.push_back(firstPair.second);
		mainChain.push_back(secondPair.second);
		pend.push_back(firstPair.first);
		pend.push_back(secondPair.first);
	}
	if (originalSize % 2 != 0)
	{
		mainChain.push_back((*itBegin).second);
		pend.push_back((*itBegin).first);
	}
}

bool	_customComparator(std::list<unsigned int> subList, unsigned int target)
{
	numberOfCmpList++;
	return (subList.back() <= target);
}

void	makePair(PairList& pair, std::list<unsigned int> list)
{
	std::list<unsigned int> first;
	std::list<unsigned int> second;

	size_t leftSize = list.size();
	leftSize = (leftSize % 2 == 0) ? leftSize : leftSize - 1;
	size_t i = 0;
	for (list_Iter it = list.begin(); it != list.end() && i < leftSize; it++)
	{
		if (i < leftSize / 2)
			first.push_back(*it);
		else
			second.push_back(*it);
		i++;
	}
	pair = std::make_pair(first, second);
}

void	customAdvence(listOfLists_Iter& it, size_t distance)
{
	for (size_t i = 0; i < distance; i++)
		it++;
}

void	mergeInsertionUsingList(t_listDataHolder& data)
{
	ListOfLists mainChain; 
	ListOfLists pend;
	std::list<unsigned int> rest;
	size_t	actualSize = data.listOfPairs.size();

	if (actualSize == 0)
		createPairs(data, rest);
	else
	{
		size_t listOfPairSize = (actualSize % 2 == 0 ? actualSize : actualSize - 1);
		size_t i = 0;
		listOfPairs_Iter it = data.listOfPairs.begin();
		while (i != listOfPairSize && it != data.listOfPairs.end())
		{
			std::list<unsigned int> first;
			std::list<unsigned int> second;
			pairToSingleList(first, *it);
			it++;
			pairToSingleList(second, *it);
			it++;
			numberOfCmpList++;
			if (first.back() > second.back())
				data.listOfPairs.push_back(std::make_pair(second, first));
			else
				data.listOfPairs.push_back(std::make_pair(first, second));
			i += 2;
		}
		if (actualSize % 2 != 0)
			pairToSingleList(rest, *it);
		listOfPairs_Iter itEnd = data.listOfPairs.begin();
		for (size_t i = 0; i < actualSize && itEnd != data.listOfPairs.end();i++)
			itEnd++;
		data.listOfPairs.erase(data.listOfPairs.begin(), itEnd);
	}

	if (data.listOfPairs.size() > 1)
		mergeInsertionUsingList(data);

	fillMainAndPendChain(mainChain, pend, data.listOfPairs);

	//	push rest to pend
	if (rest.size())
		pend.push_back(rest);

	size_t	pendSize = pend.size();
	std::vector<unsigned int> sequence = createJacobsthalSequence(pendSize + 1);

	//insert to first elem of pend to the mainChain
	if (pendSize)
		mainChain.insert(mainChain.begin(), pend.front());

	size_t	pos;
	size_t	added = 1;
	size_t	lastEndp = 1;
	//start inseting elements of the pend to the mainChain using Jacob Sequence
	for (size_t i = 0; i < sequence.size(); i++)
	{
		pos = sequence[i];
		listOfLists_Iter it;
		unsigned int target;
		while (lastEndp < pos)
		{
			listOfLists_Iter itPend = pend.begin();
			listOfLists_Iter itEnd = mainChain.begin();
			customAdvence(itPend, pos - 1);
			target = itPend->back();
			customAdvence(itEnd, (pos - 1) + added);
			it = std::lower_bound(mainChain.begin(), itEnd, target, _customComparator);
			mainChain.insert(it, *itPend);
			pos--;
			added++;
		}
		lastEndp = sequence[i];
	}
	pend.clear();
	
	//make pairs again and fill the list of pairs
	data.listOfPairs.clear();
	for (listOfLists_Iter it = mainChain.begin(); it != mainChain.end(); it++)
	{
		PairList pairOfList;
		makePair(pairOfList, *it);
		data.listOfPairs.push_back(pairOfList);
	}

	//push the final result to the mainContainer 
	if (mainChain.front().size() == 1)
	{
		for (listOfLists_Iter it = mainChain.begin(); it != mainChain.end(); it++)
			data.mainContainer.push_back((*it).front());
	}
}

std::list<unsigned int>	vectorToList(std::vector<unsigned int> parsed)
{
	std::list<unsigned int> list;
	for (size_t i = 0; i < parsed.size();i++)
		list.push_back(parsed[i]);
	return (list);
}

void	printSimpleVector(std::string msg, std::vector<unsigned int> vec)
{
	std::cout << msg;
	for (size_t i = 0; i < vec.size();i++)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << " ";	
	}
	std::cout << std::endl;
}

// void	PmergeMe(std::vector<unsigned int> numbers)
// {
// 	t_vectorDataHolder	vecDataHolder;
// 	t_listDataHolder	listDataHolder;
// 	clock_t timeReqForVector;
//     clock_t timeReqForList;

// 	vecDataHolder.mainContainer = numbers; 
// 	listDataHolder.mainContainer = vectorToList(vecDataHolder.mainContainer);

// 	printSimpleVector("Before: ", vecDataHolder.mainContainer);
// 	timeReqForVector = clock();
// 	mergeInsertionUsingVector(vecDataHolder);
// 	timeReqForVector = clock() - timeReqForVector;
// 	std::cout << "Number of comparaison for vector: " << numberOfCmpVec << std::endl;
// 	timeReqForList = clock();
// 	mergeInsertionUsingList(listDataHolder);
// 	timeReqForList = clock() - timeReqForList;
// 	printSimpleVector("After: ", vecDataHolder.mainContainer);
// 	std::cout << "Time to process a range of " << numbers.size() << " elements with std::vector : " << static_cast<float>(timeReqForVector) * 1000 / CLOCKS_PER_SEC << " us" << std::endl;
// 	std::cout << "Time to process a range of " << numbers.size() << " elements with std::list : " << static_cast<float>(timeReqForList) * 1000 / CLOCKS_PER_SEC << " us" << std::endl;
// 	std::cout << "Number of comparaison for list: " << numberOfCmpList << std::endl;
// 	return ;
// }


void	PmergeMe(std::vector<unsigned int> numbers)
{
	t_vectorDataHolder	vecDataHolder;
	t_listDataHolder	listDataHolder;
	clock_t timeReqForVector;
    clock_t timeReqForList;

	vecDataHolder.mainContainer = numbers; 
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
