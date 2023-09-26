/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:53:12 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/26 13:52:41 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("test", 150);
	Bureaucrat b2("test2", 1);

	std::cout << b << std::endl;
	std::cout << b2 << std::endl;
	try
	{
		std::cout << b << std::endl;
		std::cout << b2 << std::endl;
		b.DownGrade();
		b2.upGrade();
		std::cout << b << std::endl;
		std::cout << b2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
