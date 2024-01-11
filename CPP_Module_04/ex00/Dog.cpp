/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:19:03 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/11 21:33:07 by fedmarti         ###   ########.fr       */
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
	std::cout << "Dog constructed" << std::endl;
	this->_type = "Dog";
}

Dog::Dog( Dog & ref ) : Animal( static_cast<Animal &>(ref))
{
	std::cout << "Dog constructed" << std::endl;
	this->_type = ref._type;
}

Dog::~Dog( void )
{
	std::cout << "Dog deconstructed" << std::endl;
	this->_type = "Animal";
}

Dog & Dog::operator=( Dog & rhs )
{
	this->_type = rhs._type;
	return (*this);
}