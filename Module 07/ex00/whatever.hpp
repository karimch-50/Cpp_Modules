/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:59:14 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/19 20:51:45 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

template<typename T>
void	swap(T& arg1, T& arg2)
{
	T tmp(arg1);

	arg1 = arg2;
	arg2 = tmp;
}

template<typename T>
const T& min(const T& arg1, const T& arg2)
{
	return (arg1 < arg2 ? arg1 : arg2);
}

template<typename T>
const T& max(const T& arg1, const T& arg2)
{
	return (arg1 > arg2 ? arg1 : arg2);
}

#endif