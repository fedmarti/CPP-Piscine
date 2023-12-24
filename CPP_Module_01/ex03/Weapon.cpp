/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 00:52:58 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/24 01:34:59 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void	Weapon::setType( std::string type )
{
	this->_type = type;
}

std::string	Weapon::getType( void ) const
{
	return this->_type;
}

Weapon::Weapon( std::string type ) : _type(type)
{
	return ;
}

Weapon::Weapon( void )
{
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}