/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:25:19 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/20 18:59:14 by kchaouki         ###   ########.fr       */
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
		std::string	phoneNumber;
	public:
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNakeName(void);
		std::string getDarkestSecret(void);
		std::string	getPhoneNumber(void);
		void		setFirstName(std::string _firstName);
		void		setLastName(std::string _lastName);
		void		setNakeName(std::string _nakeName);
		void		setDarkestSecret(std::string _darkestSecret);
		void		setPhoneNumber(std::string _phoneNumber);
};

#endif