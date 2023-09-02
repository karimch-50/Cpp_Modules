/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:55:08 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/02 10:18:37 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::f_bits = 8;

Fixed::Fixed()
{
	fp_number = 0;
}

Fixed::Fixed(const int _num)
{
	fp_number = _num * (1 << f_bits);
}

Fixed::Fixed(const float _num)
{
	fp_number = roundf(_num * (1 << f_bits));
}

Fixed::~Fixed()
{

}

/*------------------operator overloading-----------------------*/

Fixed& Fixed::operator=(const Fixed& _assignment)
{
	this->fp_number = _assignment.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed& _assignment)
{
	this->fp_number += _assignment.fp_number;
	return (*this);
}

Fixed	Fixed::operator-(const Fixed& _assignment)
{
	this->fp_number -= _assignment.fp_number;
	return (*this);
}

Fixed	Fixed::operator*(const Fixed& _assignment)
{
	return (Fixed((float)(this->fp_number * _assignment.fp_number) / (1 << (2 * f_bits))));
}

Fixed	Fixed::operator/(const Fixed& _assignment)
{
	return (Fixed((float)this->fp_number / _assignment.fp_number));
}

bool	Fixed::operator>(const Fixed& _assignment)
{
	return (this->fp_number > _assignment.fp_number);
}

bool	Fixed::operator>=(const Fixed& _assignment)
{
	return (this->fp_number >= _assignment.fp_number);
}

bool	Fixed::operator<(const Fixed& _assignment)
{
	return (this->fp_number < _assignment.fp_number);	
}

bool	Fixed::operator<=(const Fixed& _assignment)
{
	return (this->fp_number <= _assignment.fp_number);	
}

bool	Fixed::operator==(const Fixed& _assignment)
{
	return (this->fp_number == _assignment.fp_number);
}

bool	Fixed::operator!=(const Fixed& _assignment)
{
	return (this->fp_number != _assignment.fp_number);
}

Fixed&	Fixed::operator++()
{
	++fp_number;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed fxd = *this;
	++fp_number;
	return (fxd);
}

Fixed&	Fixed::operator--()
{
	--fp_number;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed fxd = *this;
	--fp_number;
	return (fxd);
}

Fixed& Fixed::min(Fixed& nbr1, Fixed& nbr2)
{
	return (nbr1.fp_number < nbr2.fp_number ? nbr1 : nbr2);
}

const Fixed&	Fixed::min(const Fixed& nbr1, const Fixed& nbr2)
{
	return (nbr1.fp_number < nbr2.fp_number ? nbr1 : nbr2);
}

Fixed&	Fixed::max(Fixed& nbr1, Fixed &nbr2)
{
	return (nbr1.fp_number > nbr2.fp_number ? nbr1 : nbr2);
}

const Fixed&	Fixed::max(const Fixed& nbr1, const Fixed &nbr2)
{
	return (nbr1.fp_number > nbr2.fp_number ? nbr1 : nbr2);
}

Fixed::Fixed(const Fixed& _copy)
{
	*this = _copy;
}

void		Fixed::setRawBits(int const raw)
{
	fp_number = raw;
}

int	Fixed::getRawBits(void) const
{
	return (fp_number);
}

float		Fixed::toFloat(void) const
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
