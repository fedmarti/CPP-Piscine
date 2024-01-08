/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:50:01 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/05 18:57:38 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

void	WrongCat::makeSound( void ) const
{
	std::cout << "*Meow*" << std::endl;
}

WrongCat::WrongCat( void )
{
	this->_type = "WrongCat";
	return ;
}

WrongCat::WrongCat( WrongCat & ref ) : WrongAnimal( static_cast<WrongAnimal &>(ref))
{
	if (ref._type == "Dog")
		std::cout << "What da dog doin?\n";
	return ;
}

WrongCat::~WrongCat( void )
{
	this->_type = "Animal";
}

WrongCat & WrongCat::operator=( WrongCat & rhs )
{
	if (rhs.getType() == "Dog")
		std::cout << "What da dog doin?\n";
	else if ( rhs.getType() == "WrongCat")
		this->_type = rhs._type;
	return (*this);
}