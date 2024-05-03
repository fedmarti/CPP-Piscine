/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:24:29 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/04 01:23:50 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>
#include <climits>
#include <cfloat>
#include <cmath>
#include <cstdlib>

static void	_out_c(char c)
{
	cout << "char: ";
	if (isprint(c))
		cout << c << endl;
	else
		cout << "Non displayable" << endl;
}

static void _out_c(string out)
{
	cout << "char: " << out << endl;
}

static void	_out_i(int i)
{
	cout << "int: " << i << endl;
}

static void	_out_i(string out)
{
	cout << "int: " << out << endl;
}

static void _out_f(float f)
{

	cout << "float: " << f;
	if (static_cast<int>(f) == f)
		cout << ".0";
	cout << "f" << endl;
}

static void _out_d(double d)
{
	cout << "double: " << d;
	if (static_cast<int>(d) == d)
		cout << ".0";
	cout << endl;
}

static void _out_f(string out)
{
	cout << "float: " << out << endl;
}

static void _out_d(string out)
{
	cout << "double: " << out << endl;
}

static void	_print_int(string literal)
{
	int 	i = atoi(literal.c_str());
	char	c;
	float	f;
	double	d;

	if (isprint(i))
	{
		c = static_cast<char>(i);
		_out_c(c);
	}
	else if (i > 0 && i < CHAR_MAX)
		_out_c("");
	else
		_out_c("Impossible");
	_out_i(i);
	f = i;
	_out_f(f);
	d = i;
	_out_d(d);
}

static void _print_char(string literal)
{
	char	c = *literal.begin();
	int		i = c;
	float	f = i;
	double	d = f;

	_out_c(c);
	_out_i(i);
	_out_f(f);
	_out_d(d);
}

static void _print_float(string literal)
{
	float	f = atof(literal.c_str());
	int		i;
	char	c;
	double	d = f;
	
	if (f < INT_MIN || f > INT_MAX)
	{
		_out_c("Impossible");
		_out_i("Impossible");
	}
	else
	{
		i = static_cast<int>(f);
		c = static_cast<char>(i);
		if (i < 0 || i > CHAR_MAX)
		{
			_out_c("Impossible");
		}
		else
			_out_c(c);
		_out_i(i);
	}
	_out_f(f);
	_out_d(d);
}

static void _print_double(string literal)
{
	double	d = atof(literal.c_str());
	int		i;
	char	c;
	float	f = d;
	
	if (d < INT_MIN || d > INT_MAX)
	{
		_out_c("Impossible");
		_out_i("Impossible");
	}
	else
	{
		i = static_cast<int>(d);
		c = static_cast<char>(i);
		if (i < 0 || i > CHAR_MAX)
		{
			_out_c("Impossible");
		}
		else
			_out_c(c);
		_out_i(i);
	}
	_out_f(f);
	_out_d(d);
}

static enum conv_type	_get_type(string literal)
{
	bool 			point = false;
	enum conv_type	type = Int;
	bool			has_sign = (literal[0] == '+' || literal[0] == '-');
	bool			float_flag = false;

	if (literal.length() == 1 && !isdigit(literal[0]))
		return (Char);
	
	if (literal == "-inf" || literal == "+inf" || literal == "+inff" || literal == "-inff" || literal == "inf" || literal == "inff")
	{
		if (*(literal.end() - 1) == 'f')
			return (Inff);
		return (Inf);
	}
	
	for (string::iterator i = literal.begin() + static_cast<int>(has_sign); i != literal.end(); i++)
	{
		if (!isdigit(*i))
		{
			if (*i == '.')
			{
				if (point)
					return (Nan);
				point = true;
			}
			else if (i == literal.end() && *i == 'f')
				float_flag = true;
			else
				return (Nan);
		}
	}

	long double num;
	if (float_flag)
		num = strtof(literal.c_str(), NULL);
	else
		num = strtod(literal.c_str(), NULL);
	if (errno == ERANGE)
		return ((float_flag)? Inff : Inf);
	if (float_flag)
		return (Float);
	if (point || (num < INT_MIN || num > INT_MAX))
		return (Double);
	return (Int);
}

void ScalarConverter::convert(string literal)
{
	char	c = 0;
	int		i = 0;
	float	f = 0;
	double	d = 0;

	enum conv_type type = _get_type(literal);
	switch (type)
	{
	case Char:
		c = literal[0];
		i = static_cast<int>(c);
		f = static_cast<float>(i);
		d = f;
		break;
	case Int:
		i = atoi(literal.c_str());
		c = static_cast<char>(i);
		f = i;
		d = i;
		break;
	case Float:
		f = atof(literal.c_str());
		d = f;
		i = static_cast<int>(f);
		c = static_cast<char>(i);
		break;
	case Double:
		d = atof(literal.c_str());
		f = static_cast<float>(d);
		i = static_cast<int>(f);
		c = static_cast<char>(i);
		break;
	case Inf: case Inff:
		d = (literal[0] == '-')? DBL_MIN : DBL_MAX;
		f = (literal[0] == '-')? FLT_MIN : FLT_MAX;
		i = (literal[0] == '-')? INT_MIN : INT_MAX;
		c = (literal[0] == '-')? CHAR_MIN : CHAR_MAX;
		break;
	default:
		break;
	}
	if (static_cast<int>(c) != i || type == Nan || type == Inff || type == Inf)
		_out_c("Impossible");
	else
		_out_c(c);
	if (static_cast<long>(i) != static_cast<long>(f) || type == Nan || type == Inff || type == Inf)
		_out_i("Impossible");
	else
		_out_i(i);
	if (type == Nan)
	{
		_out_f("Nanf");
		_out_d("Nan");
	}
	else if (type == Inf || type == Inff)
	{
		if (literal[0] == '-')
		{
			_out_f("-Infinite");
			_out_d("-Infinite");
		}
		else
		{
			_out_f("Infinite");
			_out_d("Infinite");
		}
	}
	else
	{
		_out_f(f);
		_out_d(d);
	}
}

ScalarConverter::ScalarConverter( void )
{
	;
}
ScalarConverter::ScalarConverter( ScalarConverter &ref )
{
	(void)ref;
}
ScalarConverter::~ScalarConverter( void )
{
	;
}
ScalarConverter & ScalarConverter::operator = ( ScalarConverter &rhs )
{
	(void)rhs;
	return (*this);
}