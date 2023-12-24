/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:30:39 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/24 18:10:15 by fedmarti         ###   ########.fr       */
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
	harl.complain((std::string){argv[1]});
}