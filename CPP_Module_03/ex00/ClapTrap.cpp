/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:45:12 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/02 23:48:28 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

void	ClapTrap::printName( void ) const
{
	std::cout << this->_type << " " << this->_name << " ";
}

void	ClapTrap::attack( const std::string & target )
{
	this->printName();
	if (!this->_energyPoints)
	{
		std::cout << ": Not enough energy to attack\n";
		return ;
	}
	std::cout << "attacks " << target << " causing " << this->_attackDamage << " points of damage!\n";
	this->_energyPoints--;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	this->printName();
	std::cout << "took " << amount << " points of damage" << std::endl;
	this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	this->printName();
	if (!this->_energyPoints)
	{
		std::cout << ": Not enough energy to repair\n";
		return ;
	}
	std::cout << "repaired itself by " << amount << " points\n";
	this->_energyPoints--;
}


ClapTrap::ClapTrap( void ) : _name("Void"), _hitPoints(10), _energyPoints(10), _attackDamage(0), _type("ClapTrap")
{
	return ;
}

ClapTrap::ClapTrap( ClapTrap & ref ) : _name(ref._name), _hitPoints(ref._hitPoints), _energyPoints(ref._energyPoints), _attackDamage(ref._attackDamage), _type(ref._type)
{
	return ;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _type("ClapTrap")
{
	this->printName();
	std::cout << "constructed!\n";
}

ClapTrap::~ClapTrap( void )
{
	this->printName();
	std::cout << "was destroyed!\n";
}

ClapTrap & ClapTrap::operator=( ClapTrap & ref )
{
	this->_name = ref._name;
	this->_hitPoints = ref._hitPoints;
	this->_attackDamage = ref._attackDamage;
	this->_energyPoints = ref._energyPoints;
	return (*this);
}