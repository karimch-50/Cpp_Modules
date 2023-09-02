/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:23:03 by kchaouki          #+#    #+#             */
/*   Updated: 2023/09/02 10:03:47 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
	Point a(1.2, 1);
	Point b(3, 4);
	Point c(4.7f, 1);
	Point x(2, 1.5f);

	bool result = bsp(a, b, c, x);
	if (result)
		std::cout << "the point x [BELONG] to the traingle abc" << std::endl;
	else
		std::cout << "the point x [DOESN'T BELONG] to the traingle abc" << std::endl;
	return (0);
}