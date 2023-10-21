/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:21:46 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/21 11:20:42 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

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

#define MAX_VAL 750

void	intraMain()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return ;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
}

int main()
{
	Array<int> emptyArray;
	std::cout << "-------------test1----------\n";
	test1();
	std::cout << "-------------test2----------\n";
	test2();
	std::cout << "-------------intraMain----------\n";
	intraMain();
	return (0);
}
