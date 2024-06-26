/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:52:38 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/25 11:13:45 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."; 
	std::cout << " I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void	Harl::warning(void)
{	
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;	
}

void	Harl::complain(std::string level)
{
	t_funcPtr funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string  levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int lvl = 0;
	while (lvl < 4 && level != levels[lvl])
		lvl++;
	switch (lvl)
	{
		case 0 ... 3:
		{
			while (lvl < 4)
				(this->*funcs[lvl++])();
			break;
		}
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;	
	}
}
