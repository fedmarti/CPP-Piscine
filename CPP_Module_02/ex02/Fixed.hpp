/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:38:31 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/26 21:12:54 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed 
{
public:
	Fixed ( void );
	Fixed ( Fixed const & ref );
	Fixed ( const int val );
	Fixed ( const float val );
	~Fixed ( void );

	Fixed & operator = ( Fixed const & rhs );
	Fixed operator + ( Fixed const & rhs ) const;
	Fixed operator - ( Fixed const & rhs ) const;
	Fixed operator * ( Fixed const & rhs ) const;
	Fixed operator / ( Fixed const & rhs ) const;
	bool operator > ( Fixed const & rhs ) const;
	bool operator < ( Fixed const & rhs ) const;
	bool operator >= ( Fixed const & rhs ) const;
	bool operator <= ( Fixed const & rhs ) const;
	bool operator == ( Fixed const & rhs ) const;
	bool operator != ( Fixed const & rhs ) const;
	Fixed operator ++ ( void );
	Fixed operator ++ ( int );
	Fixed operator -- ( void );
	Fixed operator -- ( int );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int 	toInt( void ) const;
	
	const static Fixed & min( const Fixed & a, const Fixed & b);
	static Fixed & min( Fixed & a, Fixed & b);
	const static Fixed & max( const Fixed & a, const Fixed & b);
	static Fixed & max( Fixed & a, Fixed & b);
private:
	int _num;
	static int const _FRACTIONAL_BITS = 8;
};
	
std::ostream & operator << ( std::ostream & o, const Fixed &rhs );