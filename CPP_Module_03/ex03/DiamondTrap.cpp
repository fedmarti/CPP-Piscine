/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:23:00 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/04 22:21:31 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

void	DiamondTrap::_printName( void ) const
{
	std::cout << "DiamondTrap " << this->_name << " ";
}

void	DiamondTrap::whoAmI( void )
{
	std::string diamond = "HI, THIS IS " + this->_name + "!";
	std::string clap = "HI, THIS IS " + this->getName() + "!";
	std::string longest, shortest;
	
	longest = (this->_name.length() >= this->getName().length())? diamond : clap;
	shortest = (longest == diamond)? clap : diamond;
	std::cout << "\e[1;47m";
	for (size_t i = 0; i < shortest.length(); i++)
	{
		std::cout << "\e[1;31m" << diamond[i];
		std::cout << "\e[1;32m" << clap[i];
	}
	if (longest == diamond)
		std::cout << "\e[1;31m";
	else
		std::cout << "\e[1;32m";
	for (size_t i = shortest.length(); i < longest.length(); i++)
		std::cout << longest[i];
	std::cout << "\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap( void ) : ScavTrap("Void_clap_name"), FragTrap("Void_clap_name")
{
	this->_name = "Void";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;

}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap( std::string(name + "_clap_name") ), ScavTrap(), FragTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	this->_name = name;
	this->_printName();
	std::cout << "fused!" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap & ref ) : ScavTrap( static_cast<ScavTrap &>(ref) ), FragTrap( static_cast<FragTrap &>(ref) )
{
	this->_name = ref._name;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "it's over for ";
	this->_printName();
	std::cout << std::endl;
}