/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:08:46 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/15 10:32:36 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_sign;
		const int			grade_execute;
	public:
		Form();
		~Form();
		Form(const std::string &_name, int _grade_sign, int _garde_execute);
		Form(const Form& _copy);
		Form&	operator=(const Form& _assignment);
		const std::string	getName() const;
		int		getGradeSign() const;
		int		getGradeExecute() const;
		bool	getIsSigned() const;
		void	beSigned(const Bureaucrat& bureaucrat);

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

std::ostream&	operator<<(std::ostream& stream, const Form& form);

#endif