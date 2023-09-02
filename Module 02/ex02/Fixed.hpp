/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:55:15 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/31 16:24:20 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <fstream>
#include <cmath>

class Fixed
{
	private:
		int fp_number;
		static const int 	f_bits;
	public:
		Fixed();
		Fixed(const int _num);
		Fixed(const float _num);
		Fixed(const Fixed& _copy);
		~Fixed();		
		
		Fixed&	operator=(const Fixed& _assignment);
		Fixed	operator+(const Fixed& _assignment);
		Fixed	operator-(const Fixed& _assignment);
		Fixed	operator*(const Fixed& _assignment);
		Fixed	operator/(const Fixed& _assignment);
		
		bool	operator>(const Fixed& _assignment);
		bool	operator<(const Fixed& _assignment);
		bool	operator>=(const Fixed& _assignment);
		bool	operator<=(const Fixed& _assignment);
		bool	operator==(const Fixed& _assignment);
		bool	operator!=(const Fixed& _assignment);


		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed& min(Fixed& nbr1, Fixed& nbr2);
		static Fixed& max(Fixed& nbr1, Fixed &nbr2);
		static const Fixed& min(const Fixed& nbr1, const Fixed& nbr2);
		static const Fixed& max(const Fixed& nbr1, const Fixed &nbr2);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed);

#endif