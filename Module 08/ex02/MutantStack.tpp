/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:58:26 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/24 08:53:07 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack()
{
	std::cout << "MutantStack Default constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack Destructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& _copy)
{
	std::cout << "MutantStack Copy constructor called" << std::endl;
	*this = _copy;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& _assignement)
{
	std::cout << "MutantStack Copy assignment operator called" << std::endl;
	if (this != &_assignment)
	{
	}
	return (*this);
}

template<typename T>
void			MutantStack<T>::push(int N)
{
	
}

template<typename T>
void			MutantStack<T>::pop(void)
{
	
}

template<typename T>
int				MutantStack<T>::top(void)
{
	
}

template<typename T>
unsigned int	MutantStack<T>::size(void)
{
	
}
