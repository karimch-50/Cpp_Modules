/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:06:30 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/12 00:08:53 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& _copy){(void) _copy;}
const PmergeMe& PmergeMe::operator=(const PmergeMe& _assingnment)
{
	(void)_assingnment;
	return (*this);
}

/*========================>MERGE INSERTION USING VECTOR<========================*/
int	PmergeMe::numberOfCmpVec = 0;

void	PmergeMe::sortVectorOfPairs(PairOfTwoVector& pair)
{
	unsigned int tmp;

	numberOfCmpVec++;
	if (pair.first.back() > pair.second.back())
	{
		tmp = pair.first.back();
		pair.first.back() = pair.second.back();
		pair.second.back() = tmp;
	}
}

void	PmergeMe::createVectorOfPairs(Vector& rest)
{
	Vector_Iter itBegin = storedNumbersVec.begin();
	Vector_Iter itEnd = storedNumbersVec.end();
	size_t		OriginSize = storedNumbersVec.size();
	size_t		Size = (OriginSize % 2 == 0) ? OriginSize : OriginSize - 1;
	size_t		i = 0;
	while (i < Size && itBegin != itEnd)
	{
		PairOfTwoVector pair;
		pair.first.push_back(*itBegin);
		itBegin++;
		pair.second.push_back(*itBegin);
		itBegin++;
		vOfp.push_back(pair);
		i += 2;
	}
	if (OriginSize % 2 != 0)
		rest.push_back(*itBegin);
	for (VectorOfPairs_Iter it = vOfp.begin(); it != vOfp.end();it++)
		sortVectorOfPairs(*it);
}

void	PmergeMe::pairToSingleVector(Vector& V, PairOfTwoVector pair)
{
	for (Vector_Iter it = pair.first.begin(); it != pair.first.end(); it++)
		V.push_back(*it);
	for (Vector_Iter it = pair.second.begin(); it != pair.second.end(); it++)
		V.push_back(*it);
}

void	PmergeMe::mergeVectorOfPairs(Vector& rest)
{
	VectorOfPairs_Iter	itBegin = vOfp.begin();
	VectorOfPairs_Iter	itEnd = vOfp.end();
	size_t				Size = (vOfpSize % 2 == 0 ? vOfpSize : vOfpSize - 1);
	size_t				i = 0;
	while (i < Size && itBegin != itEnd)
	{
		PairOfTwoVector pair;
		pairToSingleVector(pair.first, *itBegin);
		itBegin++;
		pairToSingleVector(pair.second, *itBegin);
		itBegin++;
		numberOfCmpVec++;
		if (pair.first.back() > pair.second.back())
			vOfp.push_back(std::make_pair(pair.second, pair.first));
		else
			vOfp.push_back(std::make_pair(pair.first, pair.second));
		i += 2;
	}
	if (vOfpSize % 2 != 0 && vOfpSize > 1)
		pairToSingleVector(rest, *itBegin);
	vOfp.erase(vOfp.begin(), vOfp.begin() + vOfpSize);
}

void	PmergeMe::VectorOfPairsToVectorOfVector()
{
	VectorOfPairs_Iter it = vOfp.begin();
	vOfv.push_back(it->first);
	vOfv.push_back(it->second);
}

void	PmergeMe::getMainChainAndPend()
{
	VectorOfVectors mainChain = vOfv;

	pend.clear();
	vOfv.clear();
	pend.reserve(mainChain.size());
	vOfv.reserve(mainChain.size());

	vOfv.push_back(mainChain[0]);
	vOfv.push_back(mainChain[1]);
	for (size_t i = 2; i < mainChain.size(); i++)
	{
		PairTracker pair;
		pair.first = mainChain[i];
		pair.second = vOfv.end();
		i++;
		if (i < mainChain.size())
			pair.second = vOfv.insert(vOfv.end(), mainChain[i]);
		pend.push_back(pair);
	}
}

void	PmergeMe::breakDownChain()
{
	VectorOfVectors	newMainChain;

	size_t vSize = vOfv.front().size();
	if (vSize <= 1){return ;}
	for (VectorOfVector_Iter it = vOfv.begin(); it != vOfv.end(); it++)
	{
		PairOfTwoVector pair;
		size_t	i = 0;
		for (Vector_Iter iter = it->begin();iter != it->end(); iter++)
		{
			if (i < vSize / 2)
				pair.first.push_back(*iter);
			else
				pair.second.push_back(*iter);
			i++;
		}
		newMainChain.push_back(pair.first);
		newMainChain.push_back(pair.second);
	}
	vOfv.clear();
	vOfv = newMainChain;
}

Vector PmergeMe::jacobsthal_diff()
{
	Vector jacobDiff;

	unsigned long initialNumbers[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 
	349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 
	715827883, 1431655765, 2863311531, 5726623061, 11453246123, 22906492245, 45812984491, 91625968981, 183251937963};
	for (size_t	i = 0; i < 30; i++)
		jacobDiff.push_back(initialNumbers[i + 1] - initialNumbers[i]);
	return (jacobDiff);
}

bool	PmergeMe::customComparator(Vector subVec, unsigned int target)
{
	numberOfCmpVec++;
	return (subVec.back() <= target);
}

void	PmergeMe::updateTracker(VectorOfVector_Iter it)
{
	for (tracker_Iter iter = pend.begin(); iter != pend.end(); ++iter)
		if (iter->second >= it) {++iter->second;}
}

void	PmergeMe::insertPendToMainChain()
{
	Vector jacobDiff = jacobsthal_diff();
	for (size_t i = 0; pend.size(); i++)
	{
		VectorOfVector_Iter itInsertPoint;
        tracker_Iter it = pend.begin();
	
		for (size_t j = 0; j < jacobDiff[i] - 1 && it != pend.end(); ++j) {++it;}
		if (it == pend.end()) {--it;}

		while (true)
		{
			itInsertPoint = std::lower_bound(vOfv.begin(), it->second, it->first.back(), customComparator);
			VectorOfVector_Iter pos = vOfv.insert(itInsertPoint, it->first);
			updateTracker(pos);
            pend.erase(it);
            if (it == pend.begin()) break;
            --it;
		}
	}
}

void	PmergeMe::mergeInsertionUsingVector()
{
	/*=================>RECURTION<=================*/
	if (storedNumbersVec.size() == 1) {return;}
	Vector rest;
	vOfpSize = vOfp.size();
	if (vOfpSize == 0)
		createVectorOfPairs(rest);
	else
		mergeVectorOfPairs(rest);

	vOfpSize = vOfp.size();
	if (vOfpSize > 1)
		mergeInsertionUsingVector();
	/*=============>REVERSE RECURTION<=============*/
	if (vOfv.size() == 0)
		VectorOfPairsToVectorOfVector();
	
	if (rest.size() > 0) // add the back the rest to vOfv
		vOfv.push_back(rest);

	getMainChainAndPend();
	insertPendToMainChain();
	breakDownChain();

	if (vOfv.front().size() == 1) // push back the final result to storedNumbers 
	{
		storedNumbersVec.clear();
		for (VectorOfVector_Iter it = vOfv.begin();it != vOfv.end();it++)
			storedNumbersVec.push_back(it->front());
	}
}

void	PmergeMe::printSimpleVector(Vector vec)
{
	for (size_t i = 0; i < vec.size();i++)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << " ";	
	}
	std::cout << std::endl;
}

/*========================>MERGE INSERTION USING LIST<========================*/
int	PmergeMe::numberOfCmpList = 0;

void	PmergeMe::sortListOfPairs(PairOfTwoList& pair)
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

void	PmergeMe::createListOfPairs(List& rest)
{
	Vector_Iter itBegin = storedNumbersList.begin();
	Vector_Iter itEnd = storedNumbersList.end();
	size_t		OriginSize = storedNumbersList.size();
	size_t		Size = (OriginSize % 2 == 0) ? OriginSize : OriginSize - 1;
	size_t		i = 0;
	while (i < Size && itBegin != itEnd)
	{
		PairOfTwoList pair;
		pair.first.push_back(*itBegin);
		itBegin++;
		pair.second.push_back(*itBegin);
		itBegin++;
		lOfp.push_back(pair);
		i += 2;
	}
	if (OriginSize % 2 != 0)
		rest.push_back(*itBegin);
	for (ListOfPairs_Iter it = lOfp.begin(); it != lOfp.end();it++)
		sortListOfPairs(*it);
}

void	PmergeMe::pairToSingleList(List& V, PairOfTwoList pair)
{
	for (List_Iter it = pair.first.begin(); it != pair.first.end(); it++)
		V.push_back(*it);
	for (List_Iter it = pair.second.begin(); it != pair.second.end(); it++)
		V.push_back(*it);
}

void	PmergeMe::mergeListOfPairs(List& rest)
{
	ListOfPairs_Iter	itBegin = lOfp.begin();
	ListOfPairs_Iter	itEnd = lOfp.end();
	size_t				Size = (lOfpSize % 2 == 0 ? lOfpSize : lOfpSize - 1);
	size_t				i = 0;
	while (i < Size && itBegin != itEnd)
	{
		PairOfTwoList pair;
		pairToSingleList(pair.first, *itBegin);
		itBegin++;
		pairToSingleList(pair.second, *itBegin);
		itBegin++;
		numberOfCmpList++;
		if (pair.first.back() > pair.second.back())
			lOfp.push_back(std::make_pair(pair.second, pair.first));
		else
			lOfp.push_back(std::make_pair(pair.first, pair.second));
		i += 2;
	}
	if (lOfpSize % 2 != 0 && lOfpSize > 1)
		pairToSingleList(rest, *itBegin);
	ListOfPairs_Iter to = lOfp.begin();
	for (size_t i = 0; i < lOfpSize && to != lOfp.end();i++)
		to++;
	lOfp.erase(lOfp.begin(), to);
}

void	PmergeMe::ListOfPairsToListOfList()
{
	ListOfPairs_Iter it = lOfp.begin();
	lOfl.push_back(it->first);
	lOfl.push_back(it->second);
}

void	PmergeMe::_getMainChainAndPend()
{
	ListOfLists mainChain = lOfl;

	lpend.clear();
	lOfl.clear();
	lOfl.push_back(mainChain.front());
	mainChain.pop_front();
	lOfl.push_back(mainChain.front());
	mainChain.pop_front();
	while (mainChain.size())
	{
		PairTrackerL pair;
		pair.first = mainChain.front();
		mainChain.pop_front();
		pair.second = lOfl.end();
		if (mainChain.size())
			pair.second = lOfl.insert(lOfl.end(), mainChain.front());
		lpend.push_back(pair);
		if (mainChain.size())
			mainChain.pop_front();
	}
}

void	PmergeMe::_breakDownChain()
{
	ListOfLists	newMainChain;

	size_t vSize = lOfl.front().size();
	if (vSize <= 1){return ;}
	for (ListOfLists_Iter it = lOfl.begin(); it != lOfl.end(); it++)
	{
		PairOfTwoList pair;
		size_t	i = 0;
		for (List_Iter iter = it->begin();iter != it->end(); iter++)
		{
			if (i < vSize / 2)
				pair.first.push_back(*iter);
			else
				pair.second.push_back(*iter);
			i++;
		}
		newMainChain.push_back(pair.first);
		newMainChain.push_back(pair.second);
	}
	lOfl.clear();
	lOfl = newMainChain;
}

bool	PmergeMe::_customComparator(List subVec, unsigned int target)
{
	numberOfCmpList++;
	return (subVec.back() <= target);
}

void	PmergeMe::_insertPendToMainChain()
{
	Vector jacobDiff = jacobsthal_diff();
	for (size_t i = 0; lpend.size(); i++)
	{
		ListOfLists_Iter itInsertPoint;
        trackerL_Iter it = lpend.begin();
	
		for (size_t j = 0; j < jacobDiff[i] - 1 && it != lpend.end(); ++j) {++it;}
		if (it == lpend.end()) {--it;}

		while (true)
		{
			itInsertPoint = std::lower_bound(lOfl.begin(), it->second, it->first.back(), _customComparator);
			lOfl.insert(itInsertPoint, it->first);
            it = lpend.erase(it);
            if (it == lpend.begin()) break;
            --it;
		}
	}
}

void	PmergeMe::mergeInsertionUsingList()
{
	/*=================>RECURTION<=================*/
	if (storedNumbersList.size() == 1) {return;}
	List rest;
	lOfpSize = lOfp.size();
	if (lOfpSize == 0)
		createListOfPairs(rest);
	else
		mergeListOfPairs(rest);
	
	lOfpSize = lOfp.size();
	if (lOfpSize > 1)
		mergeInsertionUsingList();
	/*=============>REVERSE RECURTION<=============*/

	if (lOfl.size() == 0)
		ListOfPairsToListOfList();

	if (rest.size() > 0) // add the back the rest to lOfl
		lOfl.push_back(rest);

	_getMainChainAndPend();
	_insertPendToMainChain();
	_breakDownChain();

	if (lOfl.front().size() == 1) // push back the final result to storedNumbers 
	{
		storedNumbersList.clear();
		for (ListOfLists_Iter it = lOfl.begin();it != lOfl.end();it++)
			storedNumbersList.push_back(it->front());
	}
}

PmergeMe::PmergeMe(Vector number)
{
	storedNumbersVec = number;
	storedNumbersList = number;
	
	std::cout << "Before: ";
	printSimpleVector(storedNumbersVec);
	vOfp.reserve(storedNumbersVec.size());

	timeReqForVec = clock();
	mergeInsertionUsingVector();
	timeReqForVec = clock() - timeReqForVec;

	timeReqForList = clock();
	mergeInsertionUsingList();
	timeReqForList = clock() - timeReqForList;
	std::cout << "After: ";
	printSimpleVector(storedNumbersVec);

	std::cout << "Time to process a range of " << storedNumbersVec.size() 
			  << " elements with std::vector : "
			  << static_cast<float>(timeReqForVec) * 1000 / CLOCKS_PER_SEC << " us" << std::endl;

	std::cout << "Time to process a range of " << storedNumbersList.size()
			  << " elements with std::list : "
			  << static_cast<float>(timeReqForList) * 1000 / CLOCKS_PER_SEC << " us" << std::endl;
}
