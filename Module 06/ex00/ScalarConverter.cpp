/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:07:59 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/16 15:44:00 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& _copy)
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	(void) _copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& _assignment)
{
	std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	(void) _assignment;
	return (*this);
}

void ScalarConverter::convert(std::string str)
{
	double ret;
	char *endptr;

	ret = strtod(str.c_str(), &endptr);
	if (str == "nan" || str == "nanf" || str == "-inf" || str == "-inf" || str == "-inff" || str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << str << "f\n";
		std::cout << "double: " << str << std::endl;
	}
	
}

