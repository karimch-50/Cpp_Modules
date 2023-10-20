/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:55:10 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/20 11:16:00 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void	iter(T* arr, int size, void (*func)(T))
{
	for (int i = 0;i < size;i++)
		func(arr[i]);
}

void	printInteger(int elem)
{
	std::cout << elem << std::endl;
}

void	printString(std::string elem)
{
	std::cout << elem  << std::endl;
}

int main()
{
	int arr[5] = {1,2,3,4,5};
	std::string S[3] = {"karim", "test1", "test2"};
	iter(arr, 5, &printInteger);
	iter(S, 3, &printString);
	return (0);
}