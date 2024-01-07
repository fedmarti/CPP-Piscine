/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:20:27 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/07 23:39:54 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

void	Ice::use( ICharacter & target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}

AMateria *Ice::clone( void ) const
{
	AMateria *copy = new Ice();
	return (copy);
}

Ice::Ice( void ) : AMateria("ice")
{
	return ;
}

Ice::Ice ( Ice & ref ) : AMateria("ice")
{
	static_cast<void>(ref);
	return ;
}

Ice::~Ice( void )
{
	return ;
}

Ice & Ice::operator=( Ice & rhs )
{
	static_cast<void>(rhs);
	return (*this);
}