/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:23:03 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/16 13:31:52 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
	Point a(0, 0);
	Point b(4, 4);
	Point c(0, 8);
	Point x(0, 4);

	bool result = bsp(a, b, c, x);
	if (result)
		std::cout << "the point x [BELONG] to the traingle abc" << std::endl;
	else
		std::cout << "the point x [DOESN'T BELONG] to the traingle abc" << std::endl;
	return (0);
}