/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaouki < kchaouki@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:48:29 by kchaouki          #+#    #+#             */
/*   Updated: 2023/10/26 12:39:22 by kchaouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int getMaxDay(int year, int month)
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

static bool	hasSpacesOnly(std::string str)
{
	for (unsigned int i = 0;i < str.size();i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (false);
	}
	return (true);
}

static int	getValidDate(std::string date, std::string line)
{
	std::istringstream ss(date);
	std::tm t;
	int	dateValue;

	char* rest = strptime(date.c_str(), "%Y-%m-%d", &t);
	if (rest != NULL && (*rest == '\0' || hasSpacesOnly(rest)))
	{
		t.tm_year += 1900;
		t.tm_mon += 1;
	}
	else
		return (std::cout << "Error: Invalid date =>" << line << std::endl, -1);
	std::time_t currentTime = std::time(NULL);
   std::tm* t2 = std::localtime(&currentTime);
	if (t2 != NULL)
	{
		t2->tm_year += 1900;
		t2->tm_mon += 1;
	}
	if (t.tm_year > t2->tm_year)
		return (std::cout << "Error: Invalid date =>" << line << "\n\tcheck the year!!" << std::endl, -1);
	if (t.tm_year == t2->tm_year && t.tm_mon > t2->tm_mon)
		return (std::cout << "Error: Invalid date =>" << line << "\n\tcheck the mounth!!" << std::endl, -1);
	if (t.tm_mday > getMaxDay(t.tm_year, t.tm_mon))
		return (std::cout << "Error: Invalid date =>" << line << "\n\tcheck the day!!" << std::endl, -1);
	dateValue = t.tm_year * 10000 + t.tm_mon * 100 + t.tm_mday;
	if (dateValue < 20090203)
		return (std::cout << "Error: Invalid date =>" << line << "\n\t[bitcoin's first release was 2009-02-03]" << std::endl, -1);
	return (dateValue);
}

static float	getValidValue(std::string value, std::string line, bool maxValue)
{
	float dvalue;
	char* endptr;

	dvalue = std::strtod(value.c_str(), &endptr);
	if (*endptr != '\0' && !hasSpacesOnly(endptr))
		return (std::cout << "Error: bad input =>" << line << std::endl, -1);
	if (dvalue < 0)
		return (std::cout << "Error: not a positive number =>" << line << std::endl, -1);
	if (maxValue && dvalue > 1000)
		return (std::cout << "Error: too large a number =>" << line << std::endl, -1);
	return (dvalue);
}

static std::pair<int, float> fillDataBaseMap(std::string line)
{
	std::pair<int, float> pair;

	pair.first = getValidDate(line.substr(0, line.find(",")), line);
	if (pair.first == -1)
		return (pair);
	pair.second = getValidValue(line.substr(line.find(",") + 1, line.length()), line, false);
	return (pair);
}

static std::string trim(std::string str)
{
	size_t	start = 0;
	size_t	end = str.length() - 1;
	while (start < str.size() && (str[start] == ' ' || str[start] == '\t'))
		start++;
	while (end > 0 && (str[end] == ' ' || str[end] == '\t'))
		end--;
	return (str.substr(start, end - start + 1));
}

void	getBitcoinOnThatDate(std::map<int, float> dataBase, std::pair<int, float> toFinde, std::string line)
{
	std::map<int, float>::iterator it = dataBase.lower_bound(toFinde.first);
	float	value;

	if (it == dataBase.end() && it->first > toFinde.first)
	{
		std::cout << "date not found!!" << std::endl;
		return ;
	}
	if (it != dataBase.end() && it->first <= toFinde.first)
		value = it->second * toFinde.second;
	else
	{
		if (it != dataBase.begin())
		{
			it--;
			value = it->second * toFinde.second;	
		}
		else
		{
			std::cout << "date not found!!" << std::endl;
			return ;
		}
	}
	std::cout << line.substr(0, line.find("|")) << " => " 
				 << line.substr(line.find("|") + 1, line.length())
				 << " = " << value << std::endl;
}

int	bitcoinExchange(std::string fileName)
{
	std::map<int, float>	dataBase;
	std::pair<int, float>	pair;
	std::string	line;
	bool	checkHeader;
	bool	isFileEmpty;
	
	std::ifstream datafile("data.csv");
	if (datafile.fail())
		return (std::cout << "Failed to open the dataBase file!!" << std::endl, 1);
	checkHeader = false;
	isFileEmpty = true;
	while (std::getline(datafile, line))
	{
		if (line.empty())
			continue ;
		isFileEmpty = false;
		if (!checkHeader)
		{
			if (trim(line.substr(0, line.find(","))) != "date" \
			||  trim(line.substr(line.find(",") + 1, line.length())) != "exchange_rate")
				return (std::cout << "Error: Invalid header =>" << line << std::endl, 1);
			checkHeader = true;
			continue ;
		}
		pair = fillDataBaseMap(line);
		if (pair.first == -1 || pair.second == -1)
			continue ;
		dataBase.insert(std::make_pair(pair.first, pair.second));
	}
	if (isFileEmpty)
		return (std::cout << "Error: dataBase file is Empty!!" << std::endl, 1);
	std::ifstream infile(fileName.c_str());
	if (infile.fail())
		return (datafile.close(), std::cout << "Failed to open the input file!!" << std::endl, 1);
	checkHeader = false;
	while (std::getline(infile, line))
	{
		if (!checkHeader)
		{
			if (trim(line.substr(0, line.find("|"))) != "date" \
			||  trim(line.substr(line.find("|") + 1, line.length())) != "value")
				return (std::cout << "Error: Invalid header =>" << line << std::endl, 1);
			checkHeader = true;
			continue ;
		}
		pair.first = getValidDate(line.substr(0, line.find("|")), line);
		if (pair.first == -1)
				continue ;
		pair.second = getValidValue(line.substr(line.find("|") + 1, line.length()), line, true);
		if (pair.second == -1)
			continue ;
		getBitcoinOnThatDate(dataBase, pair, line);
	}
	datafile.close();
	infile.close();
	return (0);
}
