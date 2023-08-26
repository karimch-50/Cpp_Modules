/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:47:44 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/26 11:33:04 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int	Replace(std::string fileName, std::string toReplace, std::string replaceBy)
{
	std::string	buffer;
	std::string line;
	size_t		index;

	if (toReplace.empty())
		return (1);
	std::ifstream infile(fileName.c_str());
	if (!infile)
		return (std::cout << "failed to open the file!!" << std::endl, 1);	
	std::ofstream outfile((fileName + ".replace").c_str());
	if (!outfile)
	{
		infile.close();
		return (std::cout << "failed to create the file!!" << std::endl, 1);
	}
	while (std::getline(infile, line))
	{
		buffer = line;
		while (buffer.length() > 0)
		{
			index = buffer.find(toReplace);
			outfile << buffer.substr(0, index);
			if (index < buffer.length())
			{
				outfile << replaceBy;
				buffer = buffer.substr(index + toReplace.length(), buffer.length());
			}
			else
				break ;
		}
		if (!infile.eof())
			outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}

int main(int ac, char **av)
{
	if (ac == 4)
		return (Replace(av[1], av[2], av[3]));
	else
		std::cout << "Usage: \n\t./Replace <fileName> <toReplace> <replacedBy>" << std::endl;
	return (0);
}
