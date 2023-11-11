/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:55:10 by kchaouki          #+#    #+#             */
/*   Updated: 2023/11/10 08:19:14 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <sstream>

bool isSorted(const std::vector<int>& numbers)
{
    for (size_t i = 1; i < numbers.size(); i++)
    {
        if (numbers[i] < numbers[i - 1])
            return false;
    }
    return true;
}

int main(int ac, char **av)
{
    std::vector<int> numbers;

    std::cout << std::endl;
	if (ac < 2) {
        std::cerr << "Usage: " << av[0] << " <numbers>" << std::endl;
        return 1;
    }
	if (ac == 2)
	{
		std::string inputString = av[1];
		std::istringstream iss(inputString);
		int number;
		while (iss >> number) {
			numbers.push_back(number);
		}	
	}
	else
	{
		int i = 1;
		while (i < ac)
		{
			numbers.push_back(atoi(av[i]));
			i++;
		}
	}
    std::cout << "count is: " << numbers.size() << std::endl;
    if (isSorted(numbers))
        std::cout << "sorted\n";
    else
        std::cout << "not sorted\n";
    return 0;
}

// ARG=$(./PmergeMe `jot -r 21 1 21 | tr '\n' ' '`); ./checker $ARG 