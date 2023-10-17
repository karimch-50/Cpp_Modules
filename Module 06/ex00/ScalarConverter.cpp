/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:07:59 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/17 21:52:56 by kchaouki         ###   ########.fr       */
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

void	ConvetToCharPrinter(double dbl)
{
	std::cout << "char: ";
	if (dbl < 0 || dbl > 127 )
		std::cout << "imposible" << std::endl;
	else
	{
		if (!isprint(dbl))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << static_cast<char>(dbl) << std::endl;
	}
}

void	ConvetToIntPrinter(double dbl)
{
	std::cout << "int: ";
	if (dbl < INT_MIN || dbl > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(dbl) << std::endl;
}

void	ConvetToFloatPrinter(double dbl)
{
	std::cout << "float: ";		
	std::cout << std::setprecision(1) << static_cast<float>(dbl) << "f" << std::endl;
}

void	ConvetToDoublePrinter(double dbl)
{
	std::cout << "double: " << std::setprecision(1) << dbl << std::endl;
}

const char* ScalarConverter::ImposibleException::what() const throw()
{
	return ("char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible");
}

bool	PseudoLiteralsCheck(std::string str)
{
	std::string pseudoLiterals[6] = {"nan", "nanf", "-inf", "+inf", "-inff", "+inff"};
	for (int i = 0;i < 6;i++)
	{
		if (str == pseudoLiterals[i])
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: " << str << "\n";
			std::cout << "double: " << str << std::endl;
			return (true);
		}
	}
	return (false);
}

void ScalarConverter::convert(std::string str)
{
	double ret;
	char *endptr;

	ret = strtod(str.c_str(), &endptr);
	if (str.length() == 1 && *endptr != '\0')
		ret = static_cast<double>(*endptr);
	if (PseudoLiteralsCheck(str))
		return ;
	if (*endptr == '\0' || (*endptr == 'f' && *(endptr + 1) == '\0') || (str.length() == 1 && *endptr != '\0'))
	{
		std::cout << std::fixed;
		ConvetToCharPrinter(ret);
		ConvetToIntPrinter(ret);
		ConvetToFloatPrinter(ret);
		ConvetToDoublePrinter(ret);
	}
	else
		throw ImposibleException();
}
