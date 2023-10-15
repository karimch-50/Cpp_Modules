/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:29:59 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/15 11:12:57 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& _target) : AForm(_target, 25, 5)
{
	std::cout << "PresidentialPardonForm Constructor with param called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& _copy) : AForm(_copy)
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
	*this = _copy;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& _assignment)
{
	std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
	(void) _assignment;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if(getIsSigned() == true && executor.getGrade() <= this->getGradeExecute())
	{
		std::cout << "Informs that " << executor.getName() <<  " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	else
		throw GradeTooLowException();
}