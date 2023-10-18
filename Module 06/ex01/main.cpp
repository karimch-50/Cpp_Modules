/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:01:31 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/18 08:40:49 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data d;
	d.a = 12;
	d.b = 55;
	d.c = 'a';

	uintptr_t ptr = Serializer::serialize(&d);
	Data *d2 = Serializer::deserialize(ptr);
	std::cout << "a: " << d2->a << std::endl;
	std::cout << "b: " << d2->b << std::endl;
	std::cout << "c: " << d2->c << std::endl;
	return (0);
}
