/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:47:13 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/07 23:49:49 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure( void ) : AMateria("cure")
{
	;
}

Cure::Cure( Cure & ref ) : AMateria("cure")
{
	static_cast<void>(ref);
	;
}

Cure::~Cure()
{
	;
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria	*Cure::clone( void ) const
{
	AMateria *copy = new Cure;
	return (copy);	
}
	
Cure & Cure::operator=( Cure & rhs )
{
	static_cast<void>(rhs);
	return (*this);
}