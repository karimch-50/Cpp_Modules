/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:33:46 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/07 19:29:02 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	std::cout << "------------ test for wrong animal --------" << std::endl;

	const WrongAnimal* a = new WrongCat();
	
	std::cout << a->getType() << " " << std::endl;
	a->makeSound();
	delete a;
	
	std::cout << "------------ another tests --------" << std::endl;
	Cat* c = new Cat();
	Cat* d = new Cat(*c);

	d->makeSound();
	return 0;
}