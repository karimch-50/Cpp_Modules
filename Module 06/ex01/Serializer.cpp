/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:00:37 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/18 08:28:12 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer Default constructor called" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Serializer Destructor called" << std::endl;
}

Serializer::Serializer(const Serializer& _copy)
{
	std::cout << "Serializer Copy constructor called" << std::endl;
	(void) _copy;
}

Serializer& Serializer::operator=(const Serializer& _assignment)
{
	std::cout << "Serializer Copy assignment operator called" << std::endl;
	(void) _assignment;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
