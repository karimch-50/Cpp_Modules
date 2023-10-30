/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:58:28 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/30 12:07:20 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator cit;
		MutantStack()
		{
			std::cout << "MutantStack Default constructor called" << std::endl;
		}
		~MutantStack()
		{
			std::cout << "MutantStack Destructor called" << std::endl;

		}
		MutantStack(const MutantStack& _copy)
		{
			std::cout << "MutantStack Copy constructor called" << std::endl;
			*this = _copy;
		}
		MutantStack&	operator=(const MutantStack& _assignement)
		{
			std::cout << "MutantStack Copy assignment operator called" << std::endl;
			for (cit it = _assignement.c.begin(); it <  _assignement.c.end(); it++)
				this->c.push_back(*it);
			return (*this);
		}
		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}
};

#endif