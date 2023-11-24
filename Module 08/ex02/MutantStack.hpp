/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:58:28 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/24 11:54:12 by kchaouki         ###   ########.fr       */
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
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

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
			this->c.clear();
			for (const_iterator it = _assignement.c.begin(); it <  _assignement.c.end(); it++)
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

		reverse_iterator rbegin()
		{
			return (this->c.rbegin());
		}
		reverse_iterator rend()
		{
			return (this->c.rend());
		}

		const_iterator cbegin()
		{
			return (this->c.cbegin());
		}
		const_iterator cend()
		{
			return (this->c.cend());
		}

		const_reverse_iterator crbegin()
		{
			return (this->c.crbegin());
		}
		const_reverse_iterator crend()
		{
			return (this->c.crend());
		}
};

#endif