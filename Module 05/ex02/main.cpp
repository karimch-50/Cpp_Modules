/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:37:58 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/15 11:30:03 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b = Bureaucrat("bureaucrat_1", 2);
		// PresidentialPardonForm p = PresidentialPardonForm("test");
		// p.beSigned(b);
		// p.execute(b);

		// RobotomyRequestForm r = RobotomyRequestForm("test2");
		// r.beSigned(b);
		// r.execute(b);

		ShrubberyCreationForm s = ShrubberyCreationForm("test2");
		s.beSigned(b);
		s.execute(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (1);
}