/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:55:07 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/19 22:03:05 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void	iter(T* arr, int size, void (*func)(T))
{
	for (int i = 0;i < size;i++)
		func(arr[i]);
}
