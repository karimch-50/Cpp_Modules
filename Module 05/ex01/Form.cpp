/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 08:16:36 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/15 13:17:15 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Default"), is_signed(false), grade_sign(10), grade_execute(10)
{
	std::cout << "Form Default constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const std::string &_name, int _grade_sign, int _garde_execute) : name(_name), is_signed(false), grade_sign(_grade_sign), grade_execute(_garde_execute)
{
	std::cout << "Form Constructor with param called" << std::endl;
	if (_grade_sign < 1 || _garde_execute < 1)
		throw GradeTooHighException();
	if (_grade_sign > 150 || _garde_execute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& _copy) : name(_copy.name), grade_sign(_copy.grade_sign), grade_execute(_copy.grade_execute)
{
	std::cout << "Form Copy constructor called" << std::endl;
	*this = _copy;
}

Form&	Form::operator=(const Form& _assignment)
{
	std::cout << "Form Copy assignment operator called" << std::endl;
	if (this != &_assignment)
		is_signed = _assignment.is_signed;
	return (*this);
}

const std::string	Form::getName() const
{
	return (name);
}

int	Form::getGradeSign() const
{
	return (grade_sign);
}

int	Form::getGradeExecute() const
{
	return (grade_execute);
}

bool	Form::getIsSigned() const
{
	return (is_signed);
}

std::ostream&	operator<<(std::ostream& stream, const Form& form)
{
	stream << form.getName() << ", grade required to sign it " << form.getGradeSign() 
	<< ",  grade required to execute it " << form.getGradeExecute();
	return (stream);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form::exception=> Grade is very high!!");		
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form::exception=> Grade is very low!!");		
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > grade_sign)
		throw GradeTooLowException();
	is_signed = true;
}
