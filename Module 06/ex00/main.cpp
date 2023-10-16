/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:51:52 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/16 13:52:41 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac == 2)
	{
		try
		{
			ScalarConverter::convert(av[1]);
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cout << "Usage:\n\t./convert <argument>" << std::endl;
	return (0);
}
