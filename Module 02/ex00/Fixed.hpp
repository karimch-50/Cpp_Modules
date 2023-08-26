/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:31:08 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/26 12:31:12 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int number;
		static const int 	f_bits;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& _copy);
		Fixed&	operator=(const Fixed& _assignment);
		int		getRawBits(void) const;
		void		setRawBits(int const raw);
};

#endif