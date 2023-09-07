/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:45:37 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/07 14:34:53 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		Ideas[i] = "Default";
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain& _copy)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = _copy;
}

Brain& Brain::operator=(const Brain& _assignment)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &_assignment)
	{
		for (int i = 0; i < 100; i++)
			Ideas[i] = _assignment.Ideas[i];
	}
	return (*this);
}
