/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:06:33 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/09 11:21:56 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMR_HPP
#define PMERGEMR_HPP

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>

typedef std::pair<std::vector<unsigned int>, std::vector<unsigned int> > PairVec;
typedef std::vector<PairVec > VectorOfPairs;
typedef std::vector<std::vector<unsigned int> > VectorOfVectors;


typedef struct s_vectorDataHolder
{
	VectorOfPairs vectorOfPairs;
	std::vector<unsigned int> mainContainer;
	VectorOfVectors mainChain;
} t_vectorDataHolder;

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

void	PmergeMe(std::vector<unsigned int> numbers);

#endif