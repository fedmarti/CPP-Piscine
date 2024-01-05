/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:24:58 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/05 13:12:25 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

void	Cat::makeSound( void ) const
{
	std::cout << "*Meow*" << std::endl;
}

Cat::Cat( void )
{
	this->_type = "Cat";
	return ;
}

Cat::Cat( Cat & ref ) : Animal( static_cast<Animal &>(ref))
{
	if (ref._type == "Dog")
		std::cout << "What da dog doin?\n";
	return ;
}

Cat::~Cat( void )
{
	this->_type = "Animal";
}

Cat & Cat::operator=( Cat & rhs )
{
	if (rhs.getType() == "Dog")
		std::cout << "What da dog doin?\n";
	else if ( rhs.getType() == "Cat")
		this->_type = rhs._type;
	return (*this);
}