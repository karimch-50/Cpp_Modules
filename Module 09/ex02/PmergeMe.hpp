/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:06:33 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/11 21:07:58 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMR_HPP
#define PMERGEMR_HPP

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>

/*==============>VECTOR<===============*/
typedef std::vector<unsigned int> Vector;
typedef Vector::iterator Vector_Iter;

typedef std::pair<Vector, Vector> PairOfTwoVector;
typedef std::vector<PairOfTwoVector> VectorOfPairs;
typedef std::vector<PairOfTwoVector>::iterator VectorOfPairs_Iter;

typedef std::vector<Vector> VectorOfVectors;
typedef std::vector<Vector>::iterator VectorOfVector_Iter;

typedef std::pair<Vector, VectorOfVectors::iterator> PairTracker;
typedef std::vector<PairTracker> tracker;
typedef std::vector<PairTracker>::iterator tracker_Iter;

/*==============>LIST<===============*/
typedef std::list<unsigned int> List;
typedef List::iterator List_Iter;

typedef std::pair<List, List> PairOfTwoList;
typedef std::list<PairOfTwoList> ListOfPairs;
typedef std::list<PairOfTwoList>::iterator ListOfPairs_Iter;

typedef std::list<List> ListOfLists;
typedef std::list<List>::iterator ListOfLists_Iter;

typedef std::pair<List, ListOfLists::iterator> PairTrackerL;
typedef std::list<PairTrackerL> trackerL;
typedef std::list<PairTrackerL>::iterator trackerL_Iter;

class PmergeMe
{
	private:
		/*=========>VECTOR<=========*/
		static int		numberOfCmpVec;
		clock_t			timeReqForVec;
		Vector			storedNumbersVec;
		
		VectorOfPairs	vOfp;
		size_t			vOfpSize;

		VectorOfVectors	vOfv;
		tracker			pend;

		void	printSimpleVector(Vector vec);
		void	sortVectorOfPairs(PairOfTwoVector& pair);
		void	createVectorOfPairs(Vector& rest);
		void	pairToSingleVector(Vector& V, PairOfTwoVector pair);
		void	mergeVectorOfPairs(Vector& rest);
		void	VectorOfPairsToVectorOfVector();
		void	getMainChainAndPend();
		Vector	jacobsthal_diff();
		static bool	customComparator(Vector subVec, unsigned int target);
		void	updateTracker(VectorOfVector_Iter it);
		void	insertPendToMainChain();
		void	breakDownChain();
		void	mergeInsertionUsingVector();

		/*=========>LIST<=========*/
		static int		numberOfCmpList;
		clock_t			timeReqForList;
		Vector			storedNumbersList;

		ListOfPairs		lOfp;
		size_t			lOfpSize;

		ListOfLists		lOfl;
		trackerL		lpend;

		void	sortListOfPairs(PairOfTwoList& pair);
		void	createListOfPairs(List& rest);
		void	pairToSingleList(List& V, PairOfTwoList pair);
		void	mergeListOfPairs(List& rest);
		void	ListOfPairsToListOfList();
		void	_getMainChainAndPend();
		static bool	_customComparator(List subVec, unsigned int target);
		void	_breakDownChain();
		void	_insertPendToMainChain();
		void	mergeInsertionUsingList();

		PmergeMe();
	public:
		PmergeMe(Vector number);
		~PmergeMe();
};

#endif