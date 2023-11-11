/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:06:33 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/10 23:20:20 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMR_HPP
#define PMERGEMR_HPP

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>

typedef std::vector<unsigned int>  vector;
typedef std::vector<unsigned int>::iterator  vector_iterator;
typedef std::pair<std::vector<unsigned int>, std::vector<unsigned int> > PairVec;
typedef std::vector<PairVec > VectorOfPairs;
typedef std::vector<std::vector<unsigned int> > VectorOfVectors;


typedef std::pair<vector, VectorOfVectors::iterator> tracker_pair;
typedef std::vector<tracker_pair> tracker;
typedef std::vector<tracker_pair>::iterator tracker_Iter;

typedef struct s_vectorDataHolder
{
	VectorOfPairs vectorOfPairs;
	std::vector<unsigned int> mainContainer;
	VectorOfVectors Chain;
	tracker pend;
} t_vectorDataHolder;

// Iterators:
typedef std::vector<unsigned int>::iterator vec_Iter;
typedef VectorOfVectors::iterator vOfV_Iter;


typedef std::pair<std::list<unsigned int>, std::list<unsigned int> > PairList;
typedef std::list<PairList > ListOfPairs;
typedef std::list<std::list<unsigned int> > ListOfLists;


// Iterators:
typedef std::list<unsigned int>::iterator list_Iter;
typedef std::list<PairList >::iterator listOfPairs_Iter;
typedef std::list<std::list<unsigned int> >::iterator listOfLists_Iter;

typedef struct s_listDataHolder
{
	ListOfPairs listOfPairs;
	std::list<unsigned int> mainContainer;
} t_listDataHolder;









//to remove later
void	printVectorPair(t_vectorDataHolder data);
void	printVectorOfVectors(VectorOfVectors vOfv);
void	printPair(PairVec pairData);
void	printSimpleVector(std::vector<unsigned int> vec);
void	printSimpleList(std::list<unsigned int> list);
void	printListOfList(ListOfLists lOfl);
void	printPair(PairList pairData);
void	printListPair(t_listDataHolder data);




void	PmergeMe(std::vector<unsigned int> numbers);

#endif