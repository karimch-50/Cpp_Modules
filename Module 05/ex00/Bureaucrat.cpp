/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:53:10 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/16 08:09:32 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade) : name(_name)
{
	std::cout << "Bureaucrat Constructor with param called" << std::endl;
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	grade = _grade;
}


Bureaucrat::Bureaucrat(const Bureaucrat& _copy)
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	*this = _copy;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& _assignment)
{
	std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	if (this != &_assignment)
		grade = _assignment.grade;
	return (*this);
}

const std::string	Bureaucrat::getName(void) const
{
	return (name);
}


int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::upGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void	Bureaucrat::DownGrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (stream);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::exception=> Grade is very high!!");		
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::exception=> Grade is very low!!");		
}
