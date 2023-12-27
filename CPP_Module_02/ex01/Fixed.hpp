/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:38:31 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/26 20:30:38 by fedmarti         ###   ########.fr       */
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

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int 	toInt( void ) const;
private:
	int _num;
	static int const _FRACTIONAL_BITS = 8;
};
	
std::ostream & operator << ( std::ostream & o, const Fixed &rhs );