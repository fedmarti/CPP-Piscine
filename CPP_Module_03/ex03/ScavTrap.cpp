/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:53:47 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/04 22:16:27 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

void	ScavTrap::_printName( void ) const
{
	std::cout << "ScavTrap " << this->getName() << " ";
}

void ScavTrap::guardGate( void )
{
	this->_printName();
	if (this->_mode == GateKeeper)
	{
		std::cout << "returned to Default mode\n";
		this->_mode = Default;
	}
	else
	{
		this->_mode = GateKeeper; 
		std::cout << "is now in Gate keeper mode!\n";
	}
}

ScavTrap & ScavTrap::operator=( ScavTrap & rhs )
{
	ClapTrap *thisC = this, *rhsC = &rhs;

	this->_printName();
	std::cout << "is now ";
	*thisC = *rhsC;
	this->_printName();
	std::cout << std::endl;
	this->_mode = rhs._mode;
	return (*this);
}

void ScavTrap::attack( std::string target ) const
{
	this->_printName();
	std::cout << "hit " << target << " for " << this->_attackDamage << " points of damage!" << std::endl;
}

ScavTrap::ScavTrap( void ): ClapTrap()
{
	this->_printName();
	std::cout << "constructed\n"; 
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	this->_printName();
	std::cout << "constructed\n"; 
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap( ScavTrap & ref ) : ClapTrap( ref )
{
	this->_printName();
	std::cout << "copied\n"; 
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap( void )
{
	this->_printName();
	std::cout << "was destroyed\n";
}