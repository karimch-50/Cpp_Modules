/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:21:03 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/22 20:43:56 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string variable="HI THIS IS BRAIN";
	std::string *stringPTR = &variable;
	std::string &stringREF = variable;


	std::cout << "The memory address of the string variable: " << &variable << std::endl;
	std::cout << "The memory address held by stringPTR: " << &stringPTR << std::endl;
	std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "The value of the string variable: " << variable << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
	
	return (0);
}
