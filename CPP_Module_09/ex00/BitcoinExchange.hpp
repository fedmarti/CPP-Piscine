/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 02:22:19 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/19 06:16:17 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <map>
#include <iostream>
#include <string>

using std::string;
using std::map;

class BitcoinExchange {
public:
	class invalid_file : public std::exception
	{
		const char *what( void ) const throw();
	};
	static void print_rate( void );
	static map<string, double> rate;
	static bool init( void );
	static void	read( string filename );
private:

	static bool _parse_date(char *str, string &date);
	~BitcoinExchange( void );
	BitcoinExchange( void );
	BitcoinExchange( BitcoinExchange & ref );
	BitcoinExchange & operator = ( BitcoinExchange & rhs );
};