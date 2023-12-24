/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:12:38 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/24 00:16:29 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void	Zombie::announce( void ) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName( std::string name )
{
	this->_name = name;
}

Zombie::Zombie( std::string name ) : _name(name)
{
	return ;
}

Zombie::Zombie( void )
{
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << this->_name << ": was destroyed\n";
}
