/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:58:33 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/30 12:08:33 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <vector>

void	test1()
{
	MutantStack<int> mstack;
	MutantStack<int> mstack2;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	// //[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	mstack2 = mstack;
	it = mstack2.begin();
	ite = mstack2.end();
	std::cout << "-------------\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

#include <list>

void	test2()
{
	std::list<int> mstack;
	mstack.push_back(5);;
	mstack.push_back(17);
	// std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop_back();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	// //[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	std::cout << "------------MutantStack test---------" << std::endl;
	test1();
	std::cout << "------------list test---------" << std::endl;
	test2();
	return 0;
}