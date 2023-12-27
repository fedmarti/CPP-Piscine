/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:38:33 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/26 21:38:04 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called\n";
	return this->_num;
}

void	Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called\n";
	this->_num = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_num / (1 << Fixed::_FRACTIONAL_BITS));
}

int	Fixed::toInt( void ) const
{
	return (this->_num >> Fixed::_FRACTIONAL_BITS);
}


/*
2^-1 = 0.5
2^-2 = 0.25
2^-3 = 0.125
2^-4 = 0.0625
2^-5 = 0.03125
2^-6 = 0.015625
2^-7 = 0.0078125
2^-8 = 0.0039065 
*/

Fixed::Fixed ( void )
{
	std::cout << "Default constructor called\n";
	this->_num = 0;
}

Fixed::Fixed ( const int val )
{
	std::cout << "Int constructor called\n";
	this->_num = 0;
	this->_num = val << Fixed::_FRACTIONAL_BITS;
}

Fixed::Fixed ( const float val )
{
	std::cout << "Float constructor called\n";
	this->_num = (int)roundf(val * (1 << Fixed::_FRACTIONAL_BITS));
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

Fixed &	Fixed::operator = ( const Fixed &rhs )
{
	std::cout << "Copy assignment operator called\n";
	this->_num = rhs.getRawBits();
	return *this;
}

std::ostream & operator << ( std::ostream &output, const Fixed &rhs )
{
	output << rhs.toFloat();
	return output;
}