/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:57:32 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/23 18:39:26 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	std::cout << "Span Default constructor called" << std::endl;
}

Span::~Span()
{
	std::cout << "Span Destructor called" << std::endl;
}

Span::Span(unsigned int N)
{
	std::cout << "Span Constructor with param called" << std::endl;
	size = N;
	nbr_elements = 0;
}

Span::Span(const Span& _copy)
{
	std::cout << "Span Copy constructor called" << std::endl;
	*this = _copy;
}

Span& Span::operator=(const Span& _assignment)
{
	std::cout << "operator Copy assignment operator called" << std::endl;
	if (this != &_assignment)
	{
		this->size = _assignment.size;
		this->nbr_elements = _assignment.nbr_elements;
		for (unsigned int i = 0; i < this->size; ++i)
			this->dataHolder[i] = _assignment.dataHolder[i];
	}
	return (*this);
}

void Span::addNumber(int _N)
{
	if (nbr_elements < size)
	{
		dataHolder.push_back(_N);
		nbr_elements++;
	}
	else
		throw std::out_of_range("Span is Full!!");
}

unsigned int Span::shortestSpan()
{
	if (dataHolder.size() < 2)
		throw "list must have at least two or more elements";
	std::sort(dataHolder.begin(), dataHolder.end());
	typedef std::vector<int>::iterator VecIter;
	unsigned int shortestValue = std::numeric_limits<int>::max();;
	for (VecIter it = dataHolder.begin(); it != dataHolder.end(); it++)
		if ((it + 1) != dataHolder.end() && (shortestValue > abs(*(it + 1) - *it)))
			shortestValue = abs(*(it + 1) - *it);
	return (shortestValue);
}

unsigned int Span::longestSpan()
{
	if (dataHolder.size() < 2)
		throw "list must have at least two or more elements";
	return (abs(*std::max_element(dataHolder.begin(), dataHolder.end()) - \
					*std::min_element(dataHolder.begin(), dataHolder.end())));
}
