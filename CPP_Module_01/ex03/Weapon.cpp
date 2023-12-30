/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:52:58 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/30 19:07:59 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

void	Weapon::setType( std::string type )
{
	this->_type = type;
}

void	Weapon::setType( void * type )
{
	if (!type)
	{
		std::cerr << "Eccheccazzo!?\n";
		return ;
	}
	this->_type = std::string((char *)type);
}

std::string	Weapon::getType( void ) const
{
	return this->_type;
}

Weapon::Weapon( std::string type ) : _type(type)
{
	return ;
}

Weapon::Weapon( void * ptr ) : _type("Void Weapon")
{
	if (!ptr)
	{
		std::cerr << "A Fijodenamingotta!\n";
		return ;
	}
	this->_type = std::string((char *)ptr);
}

Weapon::Weapon( void ) : _type("Void Weapon")
{
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}