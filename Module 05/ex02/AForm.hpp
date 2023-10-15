/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:14:54 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/15 11:01:28 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_sign;
		const int			grade_execute;
	public:
		AForm();
		virtual ~AForm();
		AForm(const std::string &_name, int _grade_sign, int _garde_execute);
		AForm(const AForm& _copy);
		AForm&	operator=(const AForm& _assignment);
		const std::string	getName() const;
		int	getGradeSign() const;
		bool	getIsSigned() const;
		int		getGradeExecute() const;
		void	beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream&	operator<<(std::ostream& stream, const AForm& form);

#endif