/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:19:03 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/11 22:03:06 by fedmarti         ###   ########.fr       */
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
	this->_brain = new Brain;
	std::cout << "Dog constructed" << std::endl;
	this->_type = "Dog";
}

Dog::Dog( Dog & ref ) : Animal( static_cast<Animal &>(ref))
{
	this->_brain = new Brain;
	std::cout << "Dog constructed" << std::endl;
	*this = ref;
}

Dog::~Dog( void )
{
	delete this->_brain;
	std::cout << "Dog deconstructed" << std::endl;
	this->_type = "Animal";
}

Dog & Dog::operator=( Dog & rhs )
{
	this->_type = rhs._type;
	*this->_brain = *rhs._brain;
	return (*this);
}

Brain	*Dog::getBrain( void ) const
{
	return this->_brain;
}