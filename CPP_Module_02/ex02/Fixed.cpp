/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:38:33 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/26 22:27:35 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

int	Fixed::getRawBits( void ) const
{
	return this->_num;
}

void	Fixed::setRawBits( int const raw )
{
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
	this->_num = 0;
}

Fixed::Fixed ( const int val )
{
	this->_num = 0;
	this->_num = val << Fixed::_FRACTIONAL_BITS;
}

Fixed::Fixed ( const float val )
{
	this->_num = (int)roundf(val * (1 << Fixed::_FRACTIONAL_BITS));
}

Fixed::~Fixed ( void )
{
	return ;
}

Fixed::Fixed ( Fixed const & ref )
{
	*this = ref;
}

Fixed &	Fixed::operator = ( const Fixed &rhs )
{
	this->_num = rhs.getRawBits();
	return *this;
}


Fixed Fixed::operator + ( Fixed const & rhs ) const
{
	Fixed result;
	result.setRawBits(this->_num + rhs._num);
	return (result);
}

Fixed Fixed::operator - ( Fixed const & rhs ) const
{
	Fixed result;
	result.setRawBits(this->_num - rhs._num);
	return (result);
}

Fixed Fixed::operator * ( Fixed const & rhs ) const
{
	long tempRes = this->_num * rhs._num;
	Fixed result;
	result._num = ((int)(tempRes >> Fixed::_FRACTIONAL_BITS));
	return (result);
}

Fixed Fixed::operator / ( Fixed const & rhs ) const
{
	Fixed result((float)this->_num / rhs._num);
	return (result);
}

bool Fixed::operator > ( Fixed const & rhs ) const
{
	return this->_num > rhs._num;
}

bool Fixed::operator >= ( Fixed const & rhs ) const
{
	return this->_num >= rhs._num;
}

bool Fixed::operator < ( Fixed const & rhs ) const
{
	return this->_num < rhs._num;
}

bool Fixed::operator <= ( Fixed const & rhs ) const
{
	return this->_num <= rhs._num;
}

bool Fixed::operator == ( Fixed const & rhs ) const
{
	return this->_num == rhs._num;
}

bool Fixed::operator != ( Fixed const & rhs ) const
{
	return this->_num != rhs._num;
}

Fixed Fixed::operator ++ ( void )
{
	this->_num += 1;
	return (*this);
}

Fixed Fixed::operator -- ( void )
{
	this->_num -= 1;
	return (*this);
}

Fixed Fixed::operator ++ ( int )
{
	Fixed newF(*this);

	this->_num += 1;
	return (newF);
}

Fixed Fixed::operator -- ( int )
{
	Fixed newF(*this);

	this->_num -= 1;
	return (newF);
}

std::ostream & operator << ( std::ostream &output, const Fixed &rhs )
{
	output << rhs.toFloat();
	return output;
}

const Fixed & Fixed::min( const Fixed & a, const Fixed & b)
{
	if (a <= b)
		return a;
	return b;
}

Fixed & Fixed::min( Fixed & a, Fixed & b)
{
	if (a <= b)
		return (a);
	return (b);
}

const Fixed & Fixed::max( const Fixed & a, const Fixed & b)
{
	if (a >= b)
		return (a);
	return (b);
}

Fixed & Fixed::max( Fixed & a, Fixed & b)
{
	if (a >= b)
		return (a);
	return (b);
}