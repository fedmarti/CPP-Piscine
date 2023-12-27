/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:38:33 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/26 18:20:54 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return this->_num;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called\n";
	this->_num = raw;
}

Fixed::Fixed ( void )
{
	std::cout << "Default constructor called\n";
	this->_num = 0;
}

Fixed::~Fixed ( void )
{
	std::cout << "Destructor called\n";
	return ;
}

Fixed::Fixed ( Fixed const & ref )
{
	std::cout << "Copy constructor called\n";
	*this = ref;
}

Fixed &	Fixed::operator=( const Fixed &rhs )
{
	std::cout << "Copy assignment operator called\n";
	this->_num = rhs.getRawBits();
	return *this;
}
