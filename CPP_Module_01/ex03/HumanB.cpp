/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:52:45 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/30 19:10:02 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

void	HumanB::attack( void ) const
{
	std::cout << this->_name;
	if (!this->_weapon)
	{
		std::cout << " bitch slapped the opponent!\n";
		return ;
	}
	std::cout << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->_weapon = &weapon;
}

HumanB::HumanB( std::string name ) : _name(name)
{
	this->_weapon = NULL;
	return ;
}

HumanB::HumanB( void * name ) : _name("Default"), _weapon(NULL)
{
	if (!name)
	{
		std::cerr << "Sul serio?\n";
	}
	this->_weapon = NULL;
	return ;
}

HumanB::~HumanB( void )
{
	return ;
}