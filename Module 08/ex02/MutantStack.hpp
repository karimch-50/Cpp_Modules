/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:58:28 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/24 08:54:16 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack
{
	std::stack<int> mstack;
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack& _copy);
		MutantStack&	operator=(const MutantStack& _assignement);
		void			push(int N);
		void			pop(void);
		int				top(void);
		unsigned int	size(void);
};

#include "MutantStack.tpp"

#endif