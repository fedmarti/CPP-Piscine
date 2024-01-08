/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:30:39 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/08 20:25:03 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <cctype>

int main ( int argc, char **argv )
{
	Harl harl;
	std::string level;
	if (argc > 1)
		level = argv[1];
	else
		level = "";
	for (std::string::iterator i = level.begin(); i != level.end(); i++)
	{
		*i = toupper(*i);
	}
	harl.complain(level);
}