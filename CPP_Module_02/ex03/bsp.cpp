/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:29:52 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/10 18:07:49 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// static inline int sign(float a)
// {
// 	return (2 * (a >= 0) - 1) - (a == 0);
// }

// static inline int sign(int a)
// {
// 	return (2 * (a >= 0) - 1) - (a == 0);
// }

static inline int sign(Fixed a)
{
	return (2 * (a >= Fixed(0)) - 1) - (a == 0);
}

Fixed abs(Fixed a)
{
	if (a < Fixed(0))
		return (a * Fixed(-1));
	return (a);
}

// ax + by + c = 0

// ax + c = - by 

// ax/b + c/b = y
 
// ax/b + c/b = mx + i

// ax/b - mx = i - c/b

// (ax - mxb)/b = i - c/b 
// x(a - mb)/b = i - c/b

static Fixed get_intercept(Point A, Fixed slope)
{
	return (A.getY() - (slope * A.getX()));
}

static bool	is_within_partition(Point const A, Point const B, Point const C, Point const point)
{
	if (B.getX() == A.getX())
	{
		return (sign(A.getX() - C.getX()) == sign(A.getX() - point.getX()) \
		|| A.getX() == point.getX());
	}
	Fixed slope = (B.getY() - A.getY()) / (B.getX() - A.getX());
	Fixed yintercept = get_intercept(A, slope);

	return (sign(get_intercept(C, slope) - yintercept) == sign(get_intercept(point, slope) - yintercept));
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	if (!is_within_partition(a, b, c, point))
		return (false);
	if (!is_within_partition(b, c, a, point))
		return (false);
	return (is_within_partition(a, c, b, point));
}