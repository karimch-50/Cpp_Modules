/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:11:15 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/19 08:09:14 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern& _copy)
{
	std::cout << "Intern Copy constructor called" << std::endl;
	(void) _copy;
}

Intern& Intern::operator=(const Intern& _assignement)
{
	std::cout << "Intern Copy assignment operator called" << std::endl;
	(void) _assignement;
	return (*this);
}

AForm*	Intern::createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createPresidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string name, const std::string target)
{
	std::string names[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	AForm* (Intern::*funcs[3])(std::string) = {&Intern::createRobotomy, &Intern::createShrubbery, &Intern::createPresidentialPardon};
	int i = 0;
	while (i < 3 && name != names[i])
		i++;
    if(i < 3)
	{
		std::cout << "Intern creates " << target << std::endl;
		return (this->*funcs[i])(target);
	}
    else
		std::cout << "The form name passed as parameter doesn’t exist!!" << std::endl;
    return(NULL);
}
