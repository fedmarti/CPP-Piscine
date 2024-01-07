/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:19:03 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/05 13:17:00 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

void Dog::makeSound( void ) const
{
	std::cout << "*Woof*" << std::endl;
}

Dog::Dog( void )
{
	this->_type = "Dog";
}

Dog::Dog( Dog & ref ) : Animal( static_cast<Animal &>(ref))
{
	this->_type = ref._type;
}

Dog::~Dog( void )
{
	this->_type = "Animal";
}

Dog & Dog::operator=( Dog & rhs )
{
	this->_type = rhs._type;
	return (*this);
}