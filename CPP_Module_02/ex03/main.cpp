/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:16:06 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/09 02:23:18 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point );

Point input_point( char name )
{
	float x,y;
	
	std::cout << name << ".x: ";
	std::cin >> x;
	std::cout << " " << name << ".x: ";
	std::cin >> y;
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