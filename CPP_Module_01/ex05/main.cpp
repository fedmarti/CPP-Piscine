/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:30:39 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/08 20:25:23 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main ( int argc, char **argv )
{
	Harl harl;
	if (argc < 2)
	{
		std::cout << "Base tests: \n";
		harl.complain("Debug");
		harl.complain("Info");
		harl.complain("Warning");
		harl.complain("Error");
		return (0);
	}
	std::string level;
	if (argc > 1)
		level = argv[1];
	else
		level = "";
	for (std::string::iterator i = level.begin(); i != level.end(); i++)
	{
		if (i == level.begin())
		{
			*i = toupper(*i);
		}
		else
			*i = tolower(*i);
	}
	harl.complain(level);
}