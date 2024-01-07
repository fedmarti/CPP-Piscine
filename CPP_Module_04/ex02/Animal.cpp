/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:19:53 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/07 01:45:17 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

std::string	Animal::getType( void ) const
{
	return (this->_type);
}

void	Animal::makeSound( void ) const	
{
	std::cout << "*Animal sound*" << std::endl;
}

Brain	*Animal::getBrain( void ) const
{
	return (this->_brain);
}

Animal::Animal( void ) : _type("Animal")
{
	this->_brain = new Brain();
}

Animal::Animal( Animal & ref ) : _type(ref._type)
{
	this->_brain = new Brain();
}

Animal::~Animal( void )
{
	delete this->_brain;
}

Animal & Animal::operator=( Animal & rhs )
{
	this->_type = rhs._type;
	*this->_brain = *rhs._brain;
	return (*this);
}