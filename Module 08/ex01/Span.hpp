/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:57:36 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/23 18:46:55 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>

class Span
{
	unsigned int size;
	unsigned int nbr_elements;
	std::vector<int> dataHolder;
	Span();
	public:
		~Span();
		Span(unsigned int N);
		Span(const Span& _copy);
		Span& operator=(const Span& _assignment);
		void addNumber(int _N);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		template<typename T> void	addNumbers(typename T::iterator& begin, typename T::iterator& end)
		{
			
		}
};



#endif