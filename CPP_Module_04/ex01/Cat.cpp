/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:24:58 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/11 22:03:14 by fedmarti         ###   ########.fr       */
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
	std::cout << "Cat constructed" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain;
	return ;
}

Cat::Cat( Cat & ref ) : Animal( static_cast<Animal &>(ref))
{
	std::cout << "Cat constructed" << std::endl; 
	this->_brain = new Brain;
	if (ref._type == "Dog")
		std::cout << "What da dog doin?\n";
	this->_brain = ref._brain;
}

Cat::~Cat( void )
{
	std::cout << "Cat deconstructed" << std::endl;
	delete this->_brain;
	this->_type = "Animal";
}

Cat & Cat::operator=( Cat & rhs )
{
	if (rhs.getType() == "Dog")
		std::cout << "What da dog doin?\n";
	else
		this->_type = rhs._type;
	*this->_brain = *rhs._brain;
	return (*this);
}

Brain	*Cat::getBrain( void ) const
{
	return this->_brain;
}