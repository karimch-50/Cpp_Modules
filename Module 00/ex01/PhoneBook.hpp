/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:54:45 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/20 17:21:25 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
#define	PhoneBook_HPP
#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
	private:
		Contact contacts[8];
		int		index;
	public:
		PhoneBook();
		int		addNewContact();
		void	searchContact();
		void	getAllInfos();
};

#endif
