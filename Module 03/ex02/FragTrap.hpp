/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:37:01 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/06 17:35:49 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public	ClapTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string _name);
		FragTrap(const FragTrap& _copy);
		FragTrap& operator=(const FragTrap& _assignment);
		void highFivesGuys(void);
};


#endif