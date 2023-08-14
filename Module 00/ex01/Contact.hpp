/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:25:19 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/13 11:23:02 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_HPP
#define	Contact_HPP
#include <string>
#include <iostream>

class Contact
{
	private:
		std::string firstName; 
		std::string lastName; 
		std::string nakeName; 
		std::string darkestSecret; 
		// int			phoneNumber;
	public:
		void	createNewContact();
		// void	searchContact();
};

#endif