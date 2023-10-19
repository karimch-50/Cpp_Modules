/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:04:00 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/19 08:52:49 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>

class ScalarConverter
{
	ScalarConverter();	
	public:
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& _copy);
		ScalarConverter& operator=(const ScalarConverter& _assignment);
		static void convert(std::string str);

	class ImposibleException : public std::exception
	{
		public:
			const char* what() const throw();
	};	
};

#endif
