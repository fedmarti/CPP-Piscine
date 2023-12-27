/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:16:06 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/27 01:04:40 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
bool bsp( Point const a, Point const b, Point const c, Point const point );

int main( void ) {
	Point A(0.5, 0.5), B(3, 4);
	
	B = A;

	std::cout << A.getX() << ", " << A.getY() << std::endl;
	std::cout << B.getX() << ", " << B.getY() << std::endl;
	return 0;
}