/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:19:53 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/05 12:13:15 by fedmarti         ###   ########.fr       */
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

Animal::Animal( void ) : _type("Animal")
{
	return ;
}

Animal::Animal( Animal & ref ) : _type(ref._type)
{
	return ;
}

Animal::~Animal( void )
{
	return ;
}

Animal & Animal::operator=( Animal & rhs )
{
	this->_type = rhs._type;
	return (*this);
}