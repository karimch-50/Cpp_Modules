/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:31:06 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/30 10:06:53 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::f_bits = 8;

Fixed::Fixed()
{
	fp_number = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& _assignment)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fp_number = _assignment.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed& _copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = _copy;
}

void		Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fp_number = raw;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fp_number);
}
