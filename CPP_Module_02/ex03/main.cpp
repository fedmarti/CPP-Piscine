/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:16:06 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/10 18:07:40 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point );

static Point input_point( char name )
{
	float x,y;
	
	std::cout << name << ".x: ";
	std::cin >> x;
	if (std::cin.fail() || std::cin.eof())
		return (Point(0,0));
	std::cout << " " << name << ".y: ";
	std::cin >> y;
	if (std::cin.fail() || std::cin.eof())
		return (Point(x,0));
	return (Point(x, y));
}

int main( void ) {


	Point A(input_point('A'));
	Point B(input_point('B'));
	Point C(input_point('C'));
	Point P(input_point('P'));

	std::cout << "A:" << A << " B:" << B << " C:" << C << " point:" << P << std::endl;
	std::cout << bsp(A, B, C, P) << std::endl;
	return 0;
}