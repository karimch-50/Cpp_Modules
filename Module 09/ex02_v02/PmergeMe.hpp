/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:06:33 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/09 11:17:12 by kchaouki         ###   ########.fr       */
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

void	printVectorPair(t_vectorDataHolder data);
void	printVectorOfVectors(VectorOfVectors vOfv);
void	printPair(PairVec pairData);
void	printSimpleVector(std::vector<unsigned int> vec);



class PmergeMe
{
	private:
		
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& _copy);
		PmergeMe& operator=(const PmergeMe& _assignment);
};

#endif