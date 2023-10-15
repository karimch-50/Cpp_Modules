/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:44:05 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/15 11:26:25 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& _target) : AForm(_target, 72, 45)
{
	std::cout << "RobotomyRequestForm Constructor with param called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& _copy) : AForm(_copy)
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
	*this = _copy;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& _assignment)
{
	std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	(void) _assignment;
	return (*this);
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(getIsSigned() == true && executor.getGrade() <= this->getGradeExecute())
	{
		std::srand(time(NULL));
		if (std::rand() % 2 == 0)
			std::cout << executor.getName() << " has been robotomized successfully 50% of the time" << std::endl;
		else
			std::cout << "the robotomy failed." << std::endl;
	}
	else
		throw GradeTooLowException();
}
