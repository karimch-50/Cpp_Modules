/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 09:25:19 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/15 16:30:44 by kchaouki         ###   ########.fr       */
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
		int			phoneNumber;
	public:
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNakeName(void);
		std::string getDarkestSecret(void);
		int			getPhoneNumber(void);
		int			setFirstName(std::string _firstName);
		int			setLastName(std::string _lastName);
		int			setNakeName(std::string _nakeName);
		int			setDarkestSecret(std::string _darkestSecret);
		int			setPhoneNumber(int _phoneNumber);
		// void	searchContact();
};

#endif