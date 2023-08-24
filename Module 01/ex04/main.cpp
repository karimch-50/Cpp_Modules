/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki <kchaouki@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:47:44 by kchaouki          #+#    #+#             */
/*   Updated: 2023/08/24 13:36:45 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string fileName = av[1];
		std::string toReplace = av[2];
		std::string replaceBy = av[3];
		std::ifstream infile(fileName.c_str());
		if (!infile)
		{
			std::cout << "failed to open the file!!" << std::endl;
			return (1);
		}
		std::ofstream outfile((fileName.substr(0, fileName.find(".")) + ".replace").c_str());
		if (!infile)
		{
			std::cout << "failed to create the file!!" << std::endl;
			return (1);
		}
		std::string	buffer;
		std::string line;
		size_t		index;
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
			outfile << std::endl;
		}
		infile.close();
		outfile.close();
	}
	return (0);
}
