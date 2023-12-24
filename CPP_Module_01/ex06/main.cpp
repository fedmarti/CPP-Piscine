/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:30:39 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/24 20:22:45 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main ( int argc, char **argv )
{
	Harl harl;
	std::string level;
	if (argc > 1)
		level = argv[1];
	else
		level = "";
	harl.complain((std::string){level});
}