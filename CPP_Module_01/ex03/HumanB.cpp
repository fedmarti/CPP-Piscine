/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:52:45 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/27 23:23:59 by fedmarti         ###   ########.fr       */
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

HumanB::~HumanB( void )
{
	return ;
}