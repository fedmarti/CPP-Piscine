/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:38:31 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/26 17:56:09 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed 
{
public:
	Fixed ( void );
	Fixed ( Fixed const & ref );
	~Fixed ( void );

	Fixed & operator=( Fixed const & rhs );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:
	int _num;
	static int const _FRACTIONAL_BITS = 8;
};