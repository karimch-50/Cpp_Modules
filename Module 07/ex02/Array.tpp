/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:20:06 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/20 23:45:04 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
	std::cout << "Array Default constructor called" << std::endl;
	data = new T;
	ArraySize = 0;
}

template<typename T>
Array<T>::~Array()
{
	std::cout << "Array Destructor called" << std::endl;
	if (data)
		delete [] data;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Array Constructor with param called" << std::endl;
	try
	{
		ArraySize = n;
		data = new T[ArraySize];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

template<typename T>
Array<T>::Array(const Array& _copy)
{
	std::cout << "Array Copy constructor called" << std::endl;
	data = NULL;
	*this = _copy;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& _assignment)
{
	std::cout << "Array Copy assignment operator called" << std::endl;
	if (this != &_assignment)
	{
		if (this->data)
			delete [] this->data;
		this->ArraySize = _assignment.ArraySize;
		this->data = new T[ArraySize];
		for (unsigned int i = 0; i < ArraySize; i++)
			this->data[i] = _assignment.data[i];
	}
	return (*this);
}

template<typename T>
T& Array<T>::operator[](const unsigned int& index)
{
	if (index >= ArraySize)
		throw std::out_of_range("Out Of Range Error !!");
	return (data[index]);
}

template<typename T>
unsigned int Array<T>::size(void)
{
	return (ArraySize);
}