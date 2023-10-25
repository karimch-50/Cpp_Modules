/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:58:53 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/24 16:34:30 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename T>
void easyfind(T& dataHolder, int to_find)
{
	typename T::iterator it;
	it = std::find(dataHolder.begin(), dataHolder.end(), to_find);
	if (it != dataHolder.end())
		std::cout << "element " << to_find << " found at " << std::distance(dataHolder.begin(), it ) << std::endl;
	else
		throw std::invalid_argument("element not found!!");
}

#endif
