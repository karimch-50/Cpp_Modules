/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:21:41 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/20 23:44:04 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private:
		unsigned int ArraySize;
		T *data;
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array& _copy);
		Array& operator=(const Array& _assignment);
		T& operator[](const unsigned int& index);
		unsigned int size(void);
};

#include "Array.tpp"

#endif