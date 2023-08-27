/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:44:31 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/26 18:21:49 by kchaouki         ###   ########.fr       */
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
		int		getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed);

#endif