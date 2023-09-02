/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:44:25 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/31 08:29:53 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::f_bits = 8;

Fixed::Fixed()
{
	fp_number = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int _num)
{
	std::cout << "Int constructor called" << std::endl;
	fp_number = _num * (1 << f_bits);
}

Fixed::Fixed(const float _num)
{
	std::cout << "Float constructor called" << std::endl;
	fp_number = roundf(_num * (1 << f_bits));
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
	// std::cout << "getRawBits member function called" << std::endl;
	return (fp_number);
}

float	Fixed::toFloat(void) const
{
	return ((float)fp_number / (1 << f_bits));
}

int		Fixed::toInt(void) const
{
	return (fp_number / (1 << f_bits));
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return (stream);
}
