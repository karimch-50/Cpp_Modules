/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 08:39:45 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/19 08:09:25 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& _copy);
		Intern& operator=(const Intern& _assignement);
		AForm*	createRobotomy(std::string target);
		AForm*	createShrubbery(std::string target);
		AForm*	createPresidentialPardon(std::string target);
		AForm*	makeForm(const std::string name, const std::string target);	
};

#endif