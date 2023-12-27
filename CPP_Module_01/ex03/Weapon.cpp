/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:52:58 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/27 23:38:18 by fedmarti         ###   ########.fr       */
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
		std::cout << "Eccheccazzo!?\n";
		return ;
	}
}

std::string	Weapon::getType( void ) const
{
	return this->_type;
}

Weapon::Weapon( std::string type ) : _type(type)
{
	return ;
}

Weapon::Weapon( void * ptr ) : _type("")
{
	if (!ptr)
	{
		std::cout << "A Fijodenamingotta!\n";
		return ;
	}
}

Weapon::Weapon( void ) : _type("")
{
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}