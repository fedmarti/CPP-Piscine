/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:29:14 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/09 00:38:09 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

std::ostream & operator << ( std::ostream & output, const Point &rhs )
{
	output << "{X: " << rhs.getX() << " Y: " << rhs.getY() << "}";
}

Fixed Point::getX( void ) const
{
	return this->_x;
}

Fixed Point::getY( void ) const
{
	return this->_y;
}

bool	Point::operator==( Point const & point )
{
	return (this->_x == point._x && this->_y == point._y);
}

const Point &Point::operator=(const Point &point)
{
	return point;
}

Point::Point( void ) : _x(0), _y(0)
{
	return ;
}

Point::Point( const Point & ref ) : _x(ref._x), _y(ref._y)
{
	return ;
}


Point::Point (const float x, const float y) : _x(x), _y(y)
{
	return ;
}

Point::~Point( void )
{
	return ;
}