/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:44:25 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/26 18:31:25 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::f_bits = 8;

Fixed::Fixed()
{
	number = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int _num)
{
	std::cout << "Int constructor called" << std::endl;
	number = _num << f_bits;
}

Fixed::Fixed(const float _num)
{
	std::cout << "Float constructor called" << std::endl;
	number = _num * 256;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& _assignment)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->number = _assignment.getRawBits();
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
	number = raw;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (number);
}

float		Fixed::toFloat(void) const
{
	return ((float) number / 256);
}

int		Fixed::toInt(void) const
{
	return (number >> f_bits);
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return (stream);
}
