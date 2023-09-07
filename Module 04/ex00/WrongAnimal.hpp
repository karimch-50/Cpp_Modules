/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:30:15 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/07 13:32:07 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const std::string& _type);
		WrongAnimal(const WrongAnimal& _copy);
		WrongAnimal& operator=(const WrongAnimal& _assignment);
		void	makeSound(void) const;
		const std::string&	getType(void) const;
};

#endif