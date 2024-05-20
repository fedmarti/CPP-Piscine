/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 02:22:41 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/20 20:21:45 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <string>
#include <climits>
#include <fstream>

using std::string;
using std::cout;
using std::cerr;
using std::endl;

static bool is_int(char *str, char delimiter)
{
	if (!str)
		return (false);

	// while(isspace(*str))
		// str++;
	
	// if (*str == '+' || *str == '-')
		// str++;

	if (!*str)
		return (false); 
	
	while (*str != delimiter && *str)
	{
		if (!isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}



bool BitcoinExchange::_parse_date(char *str, string &date)
{
	//check for empty string
	if (!*str)
		return (false);

	//skip space characters
	while (isspace(*str))
		str++;
		
	string helper = str;
	date = "";

	//checks if the year is comprised of integer charcters
	if (!is_int(str, '-'))
		return (false);

	//and is a between 0 and 2100
	int year = atoi(str);
	if (year < 0 || year > 2100)
		return (false);

	//adds year to date key
	date = helper.substr(0, helper.find('-'));

	//skips all digit characters until - or end 
	while (*str && *str != '-')
		str++;

	//checks if it's reached end string
	if (!*str || !*(str + 1))
		return (false);
	str++;

	///checks if the month is comprised of two digit characters and if it's between 1 and 12
	int month = atoi(str);
	if (!is_int(str, '-') || month > 12 || month < 1 || (month < 10 && *str != '0'))
		return (false);

	//appends -mm to date
	date.append("-");
	helper = str;
	date.append(helper.substr(0, 2));

	//advances by 2 check of end string
	str += 2;
	if (*str != '-' || !*(str + 1))
		return (false);
	str++;
		
	///checks if the day is comprised of two digit characters and if it's between 1 and 31 kinda
	if (!is_int(str, '\0'))
		return (false);
	int day = atoi(str);
	if (day <= 0 || \
	(day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) || \
	(day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) || \
	((day > 28 + (year % 4 == 0)) && month == 2))
		return (false);
	
	//append day to date
	helper = str;
	date.append("-");
	date.append(helper.substr(0, 2));
	return (true);
}

BitcoinExchange::BitcoinExchange( void )
{
	;
}

BitcoinExchange::~BitcoinExchange( void )
{
	;
}

BitcoinExchange::BitcoinExchange( BitcoinExchange & ref )
{
	(void)ref;
}

BitcoinExchange & BitcoinExchange::operator = ( BitcoinExchange & rhs )
{
	(void)rhs;
	return (*this);
}

bool BitcoinExchange::init( void )
{
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		cerr << "couldn't open file data.csv" << endl;
		return (0);
	}

	string line;
	while (getline(file, line))
	{
		string date;
		double val = atof(line.c_str() + line.find(',') + 1);
		line = line.substr(0, line.find(','));
		if (_parse_date(const_cast<char *>(line.c_str()), date) && (val >= 0 && val <= 1000))
		{
			rate[date] = val;
		}
	}
	file.close();
	return (1);
}

void BitcoinExchange::print_rate( void )
{
	for (map<string, double>::iterator i = rate.begin(); i != rate.end(); i++)
		cout << "map[" << i->first << "] = " << i->second << endl;
		// cout << i->first << "," << i->second << endl;
}

static bool validate_header( string line )
{
	string str = line;
	if (str.size() == 0)
		return (false);

	//skips space and tab
	str.erase(0, str.find_first_not_of(" \t"));

	//checks for word data
	if (str.substr(0, 4) != "date")
		return (false);

	str.erase(0, str.find("date") + 4);
	str.erase(0, str.find_first_not_of(" \t"));

	//check for separator
	if (str[0] != '|')
		return (false);
	str.erase(0, 1);
	str.erase(0, str.find_first_not_of(" \t"));
	
	if (str.substr(0, 5) != "value")
		return (false);
	str.erase(0, 5);
	
	//returns true if the only remaining characters are space and tab
	return (str.find_last_not_of(" \t") == string::npos);
}

void	BitcoinExchange::read( string filename )
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
	{
		cout << "Error: couldn't open file \"" << filename << endl;
		return ;
	}
	string line;
	getline(file, line);
	if (!validate_header(line))
	{
		cout << "invalid header: \"" << line << "\"" << endl;
		file.close();
		return ;
	}

	while (getline(file, line))
	{
		string date;
		double val;
		if (line.size() == 0)
			continue;
		
		if (!_parse_date(const_cast<char *>(line.substr(0, line.find("|") - 1).c_str()), date))
		{
			line.erase(0, line.find_first_not_of(" \t"));
			cout << "Error: bad input => " << line.substr(0, line.find_first_of(" \t|")) << endl;
			continue ;
		}
		if (line.find("|") == string::npos || line.find_first_of("0123456789", line.find("|")) == string::npos)
		{
			cout << "Error: bad input => " << line << endl;
			continue ;
		}

		val = atof(line.c_str() + line.find_first_of("|") + 1);
		if (val < 0)
		{
			cout << "Error: not a positive number." << endl;
			continue ;
		}
		if (val > 1000)
		{
			cout << "Error: too large a number." << endl;
			continue ; 
		}
		map<string, double>::iterator lb = rate.upper_bound(date);
		double daily_rate = 0;
		if (lb != rate.begin())
		{
			lb--;
			daily_rate = lb->second;
		}
		cout << date << " => " << val << " = " << daily_rate * val << endl;
	}
	
	file.close();
}

map<string, double> BitcoinExchange::rate;
