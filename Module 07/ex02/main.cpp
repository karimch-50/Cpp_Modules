/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:21:46 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/20 23:53:32 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void	test1()
{
	unsigned int Size = 5;
	int* array = new int(Size);
	Array<int> myArray(Size);

	std::srand(time(NULL));
	for (unsigned int i = 0; i < Size; i++)
	{
		array[i] = std::rand() % Size;
		myArray[i] = array[i];
	}
	
	for (unsigned int i = 0; i < Size; i++)
		std::cout << "myArray value: " << myArray[i] << '\n';	

	Array<int> NewArray = myArray;
	NewArray[0] = 1337;
	std::cout << "----------new array----------\n";
	for (unsigned int i = 0; i < Size; i++)
		std::cout << "NewArray value: " << NewArray[i] << '\n';	
	delete array;
}

void	test2()
{
	Array<int> randomArray(10);
	try
	{
		std::cout << randomArray[-1];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	Array<int> emptyArray;
	test1();
	test2();
	return (0);
}
