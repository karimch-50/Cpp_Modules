/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:04:00 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/16 13:53:31 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
	public:
		ScalarConverter();	
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& _copy);
		ScalarConverter& operator=(const ScalarConverter& _assignment);
		static void convert(std::string str);
		
};

#endif
