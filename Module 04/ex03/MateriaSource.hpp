/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:20:53 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/10 11:17:42 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* inventory[4];
		AMateria* trachInventory[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource& _copy);
		const MateriaSource& operator=(const MateriaSource& _assignment);
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif