/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:55:10 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/28 21:57:18 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

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

    std::cout << "\n\n";
    int i = 1;
    while (i < ac)
    {
        numbers.push_back(atoi(av[i]));
        i++;
    }
    std::cout << "count is: " << ac - 1 << std::endl;
    if (isSorted(numbers))
        std::cout << "sorted\n";
    else
        std::cout << "not sorted\n";
    return 0;
}
