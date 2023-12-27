/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:36:32 by fedmarti          #+#    #+#             */
/*   Updated: 2023/12/26 22:09:35 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 4 || argv[2][1])
	{
		std::cout << "use: " << argv[0] << " [num 1] [operator] [num2]\n";
		if (argv[2][1])
			std::cout << "arg 2 needs to be one character long\n";
		return 1;
	}
	Fixed a((float)std::atof(argv[1])), b((float)atof(argv[3]));
	std::string result;
	switch (argv[2][0])
	{
	case '+':
		std::cout << a + b << std::endl; 
		std::cout << "float result: " << a.toFloat() + b.toFloat() << std::endl; 
		break;
	case '-':
		std::cout << a - b << std::endl; 
		std::cout << "float result: " << a.toFloat() - b.toFloat() << std::endl; 
		break;
	case '*':
		std::cout << a * b << std::endl; 
		std::cout << "float result: " << a.toFloat() * b.toFloat() << std::endl; 
		break;
	case '/':
		std::cout << a / b << std::endl; 
		std::cout << "float result: " << a.toFloat() / b.toFloat() << std::endl; 
		break;
	case '<':
		result = (a < b)? "true" : "false";
		std::cout << result << std::endl; 
		result = (a.toFloat() < b.toFloat())? "true" : "false";
		std::cout << "float result: " << result << std::endl; 
		break;
	case '>':
		result = (a > b)? "true" : "false";
		std::cout << result << std::endl; 
		result = (a.toFloat() > b.toFloat())? "true" : "false";
		std::cout << "float result: " << result << std::endl; 
		break;
	case '=':
		result = (a == b)? "true" : "false";
		std::cout << result << std::endl; 
		result = (a.toFloat() == b.toFloat())? "true" : "false";
		std::cout << "float result: " << result << std::endl; 
		break;
	default:
		std::cout << "operand '" << argv[2][0] << "' not supported\n";
		return 1;
	}
}