/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:19:53 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/11 22:05:02 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

std::string	Animal::getType( void ) const
{
	return (this->_type);
}

Animal::Animal( void ) : _type("Animal")
{
	std::cout << "Animal constructed" << std::endl;
}

Animal::Animal( Animal & ref ) : _type(ref._type)
{
	std::cout << "Animal constructed" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Animal destructed" << std::endl;
}

Animal & Animal::operator=( Animal & rhs )
{
	this->_type = rhs._type;
	return (*this);
}