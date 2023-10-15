/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:53:06 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/15 10:07:54 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int				grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& _copy);
		Bureaucrat(const std::string& _name, int _grade);
		Bureaucrat&	operator=(const Bureaucrat& _assignment);
		const std::string	getName(void) const;
		int	getGrade(void) const;
		void	upGrade();
		void	DownGrade();
		void	signForm(AForm &form);
		void	executeForm(const AForm& form);
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);

#endif