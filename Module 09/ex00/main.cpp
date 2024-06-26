/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:48:07 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/26 12:07:27 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
		return (bitcoinExchange(av[1]));
	else
		std::cout << "Usage: \n\t./btc <infile>" << std::endl;
	return (0);
}
