/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:53:00 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/30 19:04:37 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

void	HumanA::attack( void ) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	return ;
}

HumanA::HumanA(void * name, Weapon &weapon) : _name("Default"), _weapon(weapon)
{
	if (!name)
	{
		std::cerr << "Allora sei stronz*\n";
		return ;
	}
	this->_name = std::string((char *)name);
}

HumanA::~HumanA( void )
{
	return ;
}