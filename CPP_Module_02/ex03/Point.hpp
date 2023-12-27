/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:29:54 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/27 00:26:04 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point {
public:
	Point( void );
	Point ( const Point & );
	Point ( const float, const float );
	~Point( void );

	bool operator == ( const Point & );
	Fixed getX ( void ) const;
	Fixed getY ( void ) const;

private:
	const Point & operator = ( const Point & );
	const Fixed _x;
	const Fixed _y;
};