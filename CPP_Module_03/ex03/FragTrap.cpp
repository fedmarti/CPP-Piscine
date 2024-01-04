/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:50:29 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/03 00:42:34 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap( void ) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_type = "FragTrap";
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_type = "FragTrap";
}
FragTrap::FragTrap( FragTrap & ref ) : ClapTrap(ref)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_type = "FragTrap";
}
FragTrap::~FragTrap( void )
{
	this->_printName();
	std::cout << "is no more!\n";
	this->_type = "ClapTrap";
}

void FragTrap::highFivesGuys( void ) const
{
	this->_printName();
	std::cout << "requested a high five..\nAccept?(Y/N)\n";
	std::string input;
	getline(std::cin, input);
	size_t firstSpace = input.find(' ');
	if (firstSpace < input.length())
		input.erase(firstSpace);
	if (input == "Y" || input == "y")
	{
		std::cout << "Request accepted!\n";
		std::cout << "yay!\n";
		return ;
	}
	else if (input == "N" || input == "n")
	{
		std::cout << "Request denied!\n";
		std::cout << ":'(\n";
		return ;
	}
	std::cout << "Request ignored...\n: |\n";
}
