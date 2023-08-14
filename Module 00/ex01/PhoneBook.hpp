/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:54:45 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/13 11:58:24 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
#define	PhoneBook_HPP
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
		int		index;
	public:
		void	addNewContact(Contact& newContact);
		void	diplayContact();
};

#endif
