/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:50:42 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/18 22:25:29 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* Base::generate(void)
{
	int randomChoice;

	std::srand(time(NULL));
	randomChoice = (std::rand() % 3) + 1;
	// std::cout << randomChoice << std::endl;
	if (randomChoice == 1)
		return (new A());
	if (randomChoice == 2)
		return (new B());
	if (randomChoice == 3)
		return (new C());
	return (NULL);
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "NOT FOUND" << std::endl; 
}

void Base::identify(Base& p)
{
	try
	{
		Base& b = dynamic_cast<A&>(p);
		(void)b;
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		(void) e;
	}

	try
	{
		Base& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		(void) e;
	}

	try
	{
		Base& b = dynamic_cast<C&>(p);
		(void)b;
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		(void) e;
	}
	std::cout << "NOT FOUND" << std::endl; 
}