/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:58:55 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/23 13:52:39 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
// #include <deque> 
// #include <list>

int main()
{
	try
	{
		std::vector<int> array;
		// std::deque<int> array;
		// std::list<int> array;
		int size = 10;
		int to_find = 6;
		std::srand(time(NULL));
		for (int i = 0;i < size;i++)
			array.push_back((rand() % 10));
		easyfind(array, to_find);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}