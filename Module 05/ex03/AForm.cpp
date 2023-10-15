/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:25:09 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/15 13:17:51 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm() : name("Default"), is_signed(false), grade_sign(10), grade_execute(10)
{
	std::cout << "AForm Default constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

AForm::AForm(const std::string &_name, int _grade_sign, int _garde_execute) : name(_name), is_signed(false), grade_sign(_grade_sign), grade_execute(_garde_execute)
{
	std::cout << "AForm Constructor with param called" << std::endl;
	if (_grade_sign < 1 || _garde_execute < 1)
		throw GradeTooHighException();
	if (_grade_sign > 150 || _garde_execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& _copy) : name(_copy.name), grade_sign(_copy.grade_sign), grade_execute(_copy.grade_execute)
{
	std::cout << "AForm Copy constructor called" << std::endl;
	*this = _copy;
}

AForm&	AForm::operator=(const AForm& _assignment)
{
	std::cout << "AForm Copy assignment operator called" << std::endl;
	if (this != &_assignment)
		is_signed = _assignment.is_signed;
	return (*this);
}

const std::string	AForm::getName() const
{
	return (name);
}

int	AForm::getGradeSign() const
{
	return (grade_sign);
}

int	AForm::getGradeExecute() const
{
	return (grade_execute);
}

bool	AForm::getIsSigned() const
{
	return (is_signed);
}

std::ostream&	operator<<(std::ostream& stream, const AForm& Aform)
{
	stream << Aform.getName() << ", grade required to sign it " << Aform.getGradeSign() 
	<< ",  grade required to execute it " << Aform.getGradeExecute();
	return (stream);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm::exception=> Grade is very high!!");		
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm::exception=> Grade is very low!!");		
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > grade_sign)
		throw GradeTooLowException();
	is_signed = true;
}
