/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:55:15 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/27 11:36:23 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <fstream>

class Fixed
{
	private:
		int number;
		static const int 	f_bits;
	public:
		Fixed();
		Fixed(const int _num);
		Fixed(const float _num);
		Fixed(const Fixed& _copy);
		~Fixed();		
		Fixed&	operator=(const Fixed& _assignment);
		Fixed&	operator+(const Fixed& _assignment);
		Fixed&	operator-(const Fixed& _assignment);
		Fixed&	operator*(const Fixed& _assignment);
		Fixed&	operator/(const Fixed& _assignment);
		bool	operator>(const Fixed& _assignment);
		bool	operator>=(const Fixed& _assignment);
		bool	operator<(const Fixed& _assignment);
		bool	operator<=(const Fixed& _assignment);
		bool	operator==(const Fixed& _assignment);
		bool	operator!=(const Fixed& _assignment);

		//pre decriment 2
		//post incriment 2
		Fixed&	operator++();
		Fixed	operator++(int);

		static int& min(int& nbr1, int& nbr2);
		static int& min(const int& nbr1, const int& nbr2);
		static int& max(int& nbr1, int &nbr2);
		static int& max(const int& nbr1, const int &nbr2);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed);

#endif