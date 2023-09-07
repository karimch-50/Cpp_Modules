/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:33:46 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/07 20:10:34 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void	test(int size)
{
	Animal** animal= new Animal*[size];

	int k = -1;
	while (++k < size)
	{
		if (k < size / 2)
			animal[k] = new Cat();
		else
			animal[k] = new Dog();
	}
	k = -1;
	while (++k < size)
		delete animal[k];
	delete [] animal;
}

void	test1()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
}

int main()
{
	std::cout << "----------- first test -----------" << std::endl;
	test1();
	std::cout << "----------- test for array of animals -----------" << std::endl;
	test(6);
	std::cout << "----------- test for deep copy -----------" << std::endl;
	Cat* cat1 = new Cat();
	Cat* cat2 = new Cat();

	*cat1 = *cat2;

	delete cat1;
	delete cat2;
	return 0;
}
