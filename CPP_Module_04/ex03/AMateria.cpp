/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:30:05 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/08 22:54:56 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria( std::string const & type ) : _type(type)
{
	;
}

std::string const & AMateria::getType( void ) const
{
	return (this->_type);
}

void	AMateria::use( ICharacter & target )
{
	std::cout << "* used " << this->getType() << " magic on " << target.getName() << " *" << std::endl;
}

AMateria::~AMateria( void )
{
	;
}

AMateria::AMateria( void ) : _type("")
{
	;
}

AMateria::AMateria( AMateria & ref ) : _type(ref._type)
{
	;
}

AMateria & AMateria::operator=( AMateria & rhs )
{
	static_cast<void>(rhs);
	return (*this);
}