/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:40:43 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/26 16:04:23 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool	isValide(std::string arg)
{
	std::string set = " +-/*";
	for (size_t i = 0; i < arg.size(); i++)
	{
		if (!std::isdigit(arg[i]) && set.find(arg[i]) == std::string::npos)
			return (false);
	}
	return (true);
}

static bool	claculateExp(std::stack<int>& stack, char op)
{
	int	nbr1;
	int	nbr2;

	if (stack.size() >= 2)
	{
		nbr1 = stack.top();
		stack.pop();
		nbr2 = stack.top();
		stack.pop();
		if (op == '-')
			stack.push(nbr2 - nbr1);
		else if (op == '+')
			stack.push(nbr2 + nbr1);
		else if (op == '*')
			stack.push(nbr2 * nbr1);
		else if (op == '/')
			stack.push(nbr2 / nbr1);
	}
	else
		return (std::cout << "Error" << std::endl, true);
	return (false);
}

int	RPN(std::string arg)
{
	std::stack<int> stack;
	int	toPush;

	if (!isValide(arg))
		return (std::cout << "Error: not a valid argument" << std::endl, 1);
	for (size_t i = 0; i < arg.size(); i++)
	{
		if (arg[i] == ' ')
			continue ;
		else if (std::isdigit(arg[i]))
		{
			toPush = strtol(arg.substr(i, arg.length()).c_str(), NULL, 10);
			if (toPush > 10)
				return (std::cout << "Error" << std::endl, 1);
			stack.push(toPush);
		}
		else
		{
			if (claculateExp(stack, arg[i]))
				return (1);
		}
	}
	if (stack.size() >= 2)
		return (std::cout << "Error" << std::endl, 1);
	std::cout << stack.top() << std::endl;
	return (0);
}
