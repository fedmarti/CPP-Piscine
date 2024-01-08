/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:01:30 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/05 19:02:30 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

std::string	WrongAnimal::getType( void ) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound( void ) const	
{
	std::cout << "*WrongAnimal sound*" << std::endl;
}

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal")
{
	return ;
}

WrongAnimal::WrongAnimal( WrongAnimal & ref ) : _type(ref._type)
{
	return ;
}

WrongAnimal::~WrongAnimal( void )
{
	return ;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal & rhs )
{
	this->_type = rhs._type;
	return (*this);
}