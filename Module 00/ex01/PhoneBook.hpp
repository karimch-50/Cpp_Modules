/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:54:45 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/15 19:50:43 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
#define	PhoneBook_HPP
#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
	private:
		Contact contacts[3];
		int		index;
	public:
		PhoneBook();
		void	addNewContact();
		void	searchContact();
		int		getIndex();
};

#endif
