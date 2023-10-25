/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:48:07 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/25 18:47:10 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <algorithm>
#include <sstream>
#include <ctime>
#include <iomanip>

int getMaxDay(int year, int month)
{
	int maxDays;

	if (month == 2)
		year % 4 == 0 ? maxDays = 29 : maxDays = 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDays = 30;
	else
		maxDays = 31;
	return (maxDays);
}

int	getValidDate(std::string date, std::string line)
{
	std::istringstream ss(date);
	std::tm t;
	int	dateValue;

	char* rest = strptime(date.c_str(), "%Y-%m-%d", &t);
	if (rest != NULL && *rest == '\0')
	{
		t.tm_year += 1900;
		t.tm_mon += 1;
	}
	else
		return (std::cout << "Error:Invalid date =>" << line << std::endl, -1);
	std::time_t currentTime = std::time(NULL);
   std::tm* t2 = std::localtime(&currentTime);
	if (t2 != NULL)
	{
		t2->tm_year += 1900;
		t2->tm_mon += 1;
	}
	if (t.tm_year > t2->tm_year)
		return (std::cout << "Error:Invalid date =>" << line << "\n\tcheck the year!!" << std::endl, -1);
	if (t.tm_year == t2->tm_year && t.tm_mon > t2->tm_mon)
		return (std::cout << "Error:Invalid date =>" << line << "\n\tcheck the mounth!!" << std::endl, -1);
	if (t.tm_mday > getMaxDay(t.tm_year, t.tm_mon))
		return (std::cout << "Error:Invalid date =>" << line << "\n\tcheck the day!!" << std::endl, -1);
	dateValue = t.tm_year * 10000 + t.tm_mon * 100 + t.tm_mday;
	if (dateValue < 20090203)
		return (std::cout << "Error:Invalid date =>" << line << "\n\t[bitcoin's first release was 2009-02-03]" << std::endl, -1);
	return (dateValue);
}

float	getValidValue(std::string value, std::string line)
{
	double fvalue;
	char* endptr;

	fvalue = std::strtod(value.c_str(), &endptr);
	// handle case of spaces [23     ]
	if (*endptr != '\0')
		return (std::cout << "Error:  bad input =>" << line << std::endl, -1);
	if (fvalue < 0)
		return (std::cout << "Error:  not a positive number =>" << line << std::endl, -1);
	// handle case of [0.]
	return (fvalue);
}

std::pair<int, int> fillDataBaseMap(std::string line)
{
	std::pair<int, float> pair;

	pair.first = getValidDate(line.substr(0, line.find(",")), line);
	pair.second = getValidValue(line.substr(line.find(",") + 1, line.length()), line);
	return (pair);
}

int	bitcoinExchange(std::string fileName)
{
	std::map<int, float> dataBase;
	std::string line;
	
	std::ifstream datafile("data.csv");
	if (datafile.fail())
		return (std::cout << "Failed to open the data file!!" << std::endl, 1);
	std::pair<int, float> pair;
	while (std::getline(datafile, line).good())
	{
		pair = fillDataBaseMap(line);
		if (pair.first == -1 || pair.second == -1)
			return (datafile.close(), 1);
		dataBase.insert(std::make_pair(pair.first, pair.second));
	}

	// for (std::map<int, float>::iterator it = dataBase.begin(); it != dataBase.end(); it++)
	// {
	// 	std::cout << "key: " << it->first << " value: " << it->second << std::endl;
	// }
	exit (1);
	std::ifstream infile(fileName.c_str());
	if (infile.fail())
		return (datafile.close(), std::cout << "Failed to open the input file!!" << std::endl, 1);
	while (std::getline(infile, line).good())
	{
		// pair = parser(line , '|');
		// toEvaluate.insert({pair.first, pair.second});
		// std::cout << line << std::endl;
	}
	datafile.close();
	infile.close();
	return (0);
}

int main(int ac, char **av)
{
	if (ac == 2)
		bitcoinExchange(av[1]);
	else
		std::cout << "Usage: \n\t./btc <infile>" << std::endl;
	return (1);
}
