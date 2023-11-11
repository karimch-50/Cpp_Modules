/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:06:30 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/11 10:42:26 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// unsigned int jacobsthal(unsigned int n)
// {
// 	if (n == 0)
// 		return (0);
// 	if (n == 1)
// 		return (1);
// 	return (jacobsthal(n - 1) + 2 * (jacobsthal(n - 2)));
// }

// std::vector<unsigned int> createJacobsthalSequence(unsigned int pendSize)
// {
// 	std::vector<unsigned int> sequence;
// 	unsigned int index = 3;
// 	unsigned int jacob;
	
// 	// std::cout << "jacobsthal pendSize: " << pendSize << std::endl;
// 	while ((jacob = jacobsthal(index)) <= pendSize)
// 	{
// 		sequence.push_back(jacob);
// 		index++;
// 	}
// 	return (sequence);
// }

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

// void	fillMainAndPendChain(VectorOfVectors& mainChain, VectorOfVectors& pend, VectorOfPairs vectorOfPairs)
void	VectorPairToVectorOfVector(t_vectorDataHolder& data)
{
	size_t	originalSize = data.vectorOfPairs.size();
	for (size_t i = 0; i < originalSize; i ++)
	{
		PairVec Pair = data.vectorOfPairs[i];

		data.Chain.push_back(Pair.first);
		data.Chain.push_back(Pair.second);
	}
	data.vectorOfPairs.clear();
}

// void	fillMainAndPendChain(VectorOfVectors& mainChain, VectorOfVectors& pend, VectorOfPairs vectorOfPairs)
// {
// 	size_t	originalSize = vectorOfPairs.size();
// 	size_t	sizeOfVectorOfPairs = (originalSize % 2 == 0 ? originalSize : originalSize - 1);
// 	size_t i = 0;
// 	if (originalSize == 1)
// 	{
// 		mainChain.push_back(vectorOfPairs[0].first);
// 		mainChain.push_back(vectorOfPairs[0].second);
// 		return ;
// 	}
// 	for (; i < sizeOfVectorOfPairs; i += 2)
// 	{
// 		PairVec firstPair = vectorOfPairs[i];
//     	PairVec secondPair = vectorOfPairs[i + 1];

// 		mainChain.push_back(firstPair.second);
// 		mainChain.push_back(secondPair.second);
// 		pend.push_back(firstPair.first);
// 		pend.push_back(secondPair.first);
// 	}
// 	if (originalSize % 2 != 0)
// 	{
// 		mainChain.push_back(vectorOfPairs[i].second);
// 		pend.push_back(vectorOfPairs[i].first);
// 	}
// }

bool	customComparator(std::vector<unsigned int> subVec, unsigned int target)
{
	numberOfCmpVec++;
	return (subVec.back() <= target);
}

void	createPairs(t_vectorDataHolder& data, std::vector<unsigned int>& rest)
{
	std::vector<unsigned int> first;
	std::vector<unsigned int> second;
	size_t originSize = data.mainContainer.size();
	size_t i = 0;

	size_t leftSize = (originSize % 2 == 0) ? originSize : originSize - 1;
	for (; i < leftSize; i += 2)
	{
		first.push_back(data.mainContainer[i]);
		second.push_back(data.mainContainer[i + 1]);
		data.vectorOfPairs.push_back(std::make_pair(first, second));
		first.clear();
		second.clear();
	}
	if (originSize % 2 != 0)
		rest.push_back(data.mainContainer[i]);
	data.mainContainer.clear();
	for (size_t i = 0; i < data.vectorOfPairs.size(); i++)
		sortPair(data.vectorOfPairs[i]);
}

void	breakDownChain(t_vectorDataHolder& data)
{
	VectorOfVectors	newMainChain;

	size_t vectorSize = data.Chain.front().size();
	for (size_t i = 0; i < data.Chain.size(); i++)
	{
		std::vector<unsigned int> vec1;
		std::vector<unsigned int> vec2;
		for (size_t j = 0;j < vectorSize; j++)
		{
			if (j < vectorSize / 2)
				vec1.push_back(data.Chain[i][j]);
			else
				vec2.push_back(data.Chain[i][j]);
		}
		newMainChain.push_back(vec1);
		newMainChain.push_back(vec2);
	}
	data.Chain.clear();
	data.Chain = newMainChain;
}

// std::vector<std::pair<std::vector<unsigned int>, std::vector<unsigned int>::iterator> > GetMainChainAndPend(t_vectorDataHolder& data)
// {
// 	std::vector<std::pair<std::vector<unsigned int>, std::vector<unsigned int>::iterator> > pend;
// 	std::vector<int> vec;
// 	std::vector<int>::iterator it = ;
// 	for (size_t i = 0;i < data.Chain.size();i++)
// 	{
// 		if (i < 2)
// 		{
// 			mainChain.push_back(data.Chain[i]);
// 			// if (i == 1 && data.Chain.size() > 2)
// 			// 	data.pend.push_back(data.Chain[i]);
// 		}
// 		else if (i % 2 == 0)
// 			data.pend.push_back(data.Chain[i]);
// 		else
// 			mainChain.push_back(data.Chain[i]);
// 	}
// 	data.Chain.clear();
// 	data.Chain = mainChain;
// }

void	GetMainChainAndPend(t_vectorDataHolder& data)
{
	VectorOfVectors mainChain = data.Chain;

	data.pend.clear();
	data.Chain.clear();
	data.Chain.reserve(mainChain.size());
	data.pend.reserve(mainChain.size());

	data.Chain.push_back(mainChain[0]);
	data.Chain.push_back(mainChain[1]);

	for (size_t i = 2; i < mainChain.size(); i++)
	{
		tracker_pair pair;
		pair.first = mainChain[i];
		pair.second = data.Chain.end();
		i++;
		if (i < mainChain.size())
			pair.second = data.Chain.insert(data.Chain.end(), mainChain[i]);
		
		data.pend.push_back(pair);
	}
}

std::vector<unsigned int> jacobsthal_diff()
{
	std::vector<unsigned int> jacobDiff;

	unsigned long initialNumbers[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 
	349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 
	715827883, 1431655765, 2863311531, 5726623061, 11453246123, 22906492245, 45812984491, 91625968981, 183251937963};
	for (size_t	i = 0; i < 30;i++)
		jacobDiff.push_back(initialNumbers[i + 1] - initialNumbers[i]);
	return (jacobDiff);
}

void	updateTracker(tracker& pend, vOfV_Iter it)
{
	for (tracker_Iter iter = pend.begin(); iter != pend.end(); ++iter)
		if (iter->second >= it) {++iter->second;}
}

void	mergeInsertionUsingVector(int depth, t_vectorDataHolder& data)
{
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
		if (actualSize % 2 != 0 && actualSize > 1)
			pairToSingleVector(rest, data.vectorOfPairs[i]);
		data.vectorOfPairs.erase(data.vectorOfPairs.begin(), data.vectorOfPairs.begin() + actualSize);
	}

	//print--------------
	// std::cout << "########################################################\n";
	// std::cout << "recurtion depth: " << depth << std::endl; 
	// std::cout << "number of comparaisons: " << numberOfCmpVec << std::endl; 
	// std::cout << "vectorOfPairs size: " << data.vectorOfPairs.size() << std::endl;
	// printVectorPair(data);
	// std::cout << "rest: ";
	// printSimpleVector(rest);

	if (data.vectorOfPairs.size() > 1)
		mergeInsertionUsingVector(depth + 1, data);

	if (data.Chain.size() == 0)
		VectorPairToVectorOfVector(data);

	if (rest.size() > 0)
		data.Chain.push_back(rest);

	// std::cout << "########################################################\n";
	// std::cout << "reverse recurtion depth: " << depth << std::endl;
	// std::cout << "number of comparaisons: " << numberOfCmpVec << std::endl;
	// std::cout << "VectorOfVector size: " << data.Chain.size() << std::endl;
	// std::cout << "Chain: ";
	// printVectorOfVectors(data.Chain);

	GetMainChainAndPend(data);
	// for (tracker_Iter it = data.pend.begin(); it != data.pend.end(); it++)
	// {
	// 	std::cout << "pend value: " << it->first.back() << std::endl;
	// 	std::cout << "Iter value: " << it->second->back() << std::endl;
	// }
	// if (data.pend.size() > 0)
	// {
	// 	tracker_Iter itrrr = data.pend.begin();
	// 	std::cout << "tracker_Iter Value: " << itrrr->second->back() << std::endl;
	// }
	// if (depth == 2)
	// 	exit (1);
	//print--------------
	// std::cout << "--------------: " << std::endl;
	// std::cout << "mainChain: ";
	// printVectorOfVectors(data.Chain);
	// std::cout << "pend:";
	// for (size_t i = 0; i < data.pend.size(); i++)
	// 	std::cout << " " << data.pend[i].first.back();
	// std::cout << std::endl;
	


	vOfV_Iter itInsertPoint;
	std::vector<unsigned int> jacobDiff = jacobsthal_diff();
	for (size_t i = 0; data.pend.size(); i++)
	{
		// std::cout << "Pend size: " << data.pend.size() << std::endl;
        tracker_Iter it = data.pend.begin();
	
		for (size_t j = 0; j < jacobDiff[i] - 1 && it != data.pend.end(); ++j)
			++it;
		
		while (true)
		{
			// std::cout << "Value pair: " << it->first.back() << std::endl;
			// std::cout << "Value chain: " << it->second->back() << std::endl;
			// std::cout << "mainChain========>";
			// printVectorOfVectors(data.Chain);
			itInsertPoint = std::lower_bound(data.Chain.begin(), it->second, it->first.back(), customComparator);
            vOfV_Iter iteeer = data.Chain.insert(itInsertPoint, it->first);
			updateTracker(data.pend, iteeer);
            data.pend.erase(it);
            if (it == data.pend.begin()) break;
            --it;
		}
	}





	// ============>with simple binary search <============
	// while (data.pend.size())
	// {
	// 	tracker_Iter it = data.pend.begin();
	// 	std::cout << "toInsert: " << it->first.back() << std::endl;
	// 	std::cout << "where: " << it->second->back() << std::endl;
	// 	vOfV_Iter iteeer;
	// 	// if (it->second != data.Chain.end())
	// 	iteeer = std::lower_bound(data.Chain.begin(), it->second, it->first.back(), customComparator);
	// 	// iteeer = std::lower_bound(data.Chain.begin(), data.Chain.end(), it->first.back(), customComparator);
		
	// 	updateTracker(data.pend, data.Chain.insert(iteeer,  it->first));
	// 	data.pend.erase(it);
	// 	std::cout << "new mainChain: ";
	// 	printVectorOfVectors(data.Chain);
	// 	// if (it == data.pend.begin()) break;
	// 	// --it;
	// }

	//print--------------
	// std::cout << "Final mainChain: ";
	// printVectorOfVectors(data.Chain);
	// std::cout << "Final pend: ";
	// printVectorOfVectors(data.pend);
	// // std::cout << "Final rest: ";
	// // printSimpleVector(rest);
	// printVectorPair(data);

	//push the final result to the mainContainer 
	if (data.Chain.front().size() == 1)
	{
		for (size_t i = 0;i < data.Chain.size();i++)
			data.mainContainer.push_back(data.Chain[i].front());
	}
	breakDownChain(data);
	return ;
}


void	PmergeMe(std::vector<unsigned int> numbers)
{
	// (void) numbers;
	t_vectorDataHolder	vecDataHolder;
	t_listDataHolder	listDataHolder;
	// clock_t timeReqForVector;
    // clock_t timeReqForList;

	vecDataHolder.mainContainer = numbers; 
	// listDataHolder.mainContainer = vectorToList(vecDataHolder.mainContainer);
	std::cout << "Before: ";
	for (size_t i = 0; i < vecDataHolder.mainContainer.size();i++)
		std::cout << vecDataHolder.mainContainer[i] << " ";
	std::cout << std::endl;
	std::cout << "========================================================" << std::endl;
	mergeInsertionUsingVector(0, vecDataHolder);
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
