/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:30:05 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/07 22:43:30 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : _type(type)
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