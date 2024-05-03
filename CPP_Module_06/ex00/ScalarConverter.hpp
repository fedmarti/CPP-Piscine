/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:24:42 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/03 23:53:59 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class ScalarConverter {
	public:
	static void convert(string literal);
	private:
	ScalarConverter( void );
	ScalarConverter( ScalarConverter & );
	~ScalarConverter( void );
	ScalarConverter & operator = ( ScalarConverter & );
};

enum conv_type {
	Int,
	Char,
	Float,
	Double,
	Inff,
	Inf,
	Nan
};