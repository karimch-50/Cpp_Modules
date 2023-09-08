/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:20:53 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/08 17:20:10 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	// private:
	// 	int	_index;
	// 	AMateria* inventory[4];
	public:
		MateriaSource();
		~MateriaSource();
		// MateriaSource(const std::string name);
		MateriaSource(const MateriaSource& _copy);
		const MateriaSource& operator=(const MateriaSource& _assignment);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif