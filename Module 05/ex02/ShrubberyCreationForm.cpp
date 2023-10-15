/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:11:55 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/15 11:29:10 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target) : AForm(_target, 145, 137)
{
	std::cout << "ShrubberyCreationForm Constructor with param called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& _copy) : AForm(_copy)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
	*this = _copy;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& _assignment)
{
	std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	(void) _assignment;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(getIsSigned() == true && executor.getGrade() <= this->getGradeExecute())
	{
		std::ofstream outfile((executor.getName() + "_shrubbery").c_str());
		outfile << "    /\\\n";
		outfile << "   //\\\\\n";
		outfile << "  //  \\\\\n";
		outfile << " //    \\\\\n";
		outfile << "   ||||";
		outfile << std::endl;
		outfile.close();
	}
	else
		throw GradeTooLowException();
}

