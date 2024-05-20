/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 03:46:12 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/20 06:23:04 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

RPN::RPN( void )
{
	;
}

RPN::~RPN( void )
{
	;
}
RPN::RPN( RPN &ref )
{
	(void)ref;
}

RPN & RPN::operator= ( RPN & rhs )
{
	(void)rhs;
	return (*this);
}


const char *RPN::GenericError::what( void ) const throw ()
{
	return ("Error");
} 
const char *RPN::MissingOperand::what( void ) const throw ()
{
	return ("Error: Missing operand");
}

const char *RPN::ZeroDivision::what( void ) const throw ()
{
	return ("Error: division by zero");
}

const char *RPN::UndefinedResult::what( void ) const throw ()
{
	return ("Result undefined");
}

const char *RPN::TooManyOperands::what( void ) const throw ()
{
	return ("Error: too many operands");
}


static bool _is_operator( char c )
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

static bool _valid_input( string input )
{
	if (input.size() == 0)
		return (false);

	for (size_t i = 0; i < input.size(); i++)
	{
		if (i % 2)
		{
			if (input[i] != ' ' && input[i] != '\t') return (false);
		}
		else
		{
			if (!isdigit(input[i]) && !_is_operator(input[i])) return (false);
		}
	}
	return (true);
}

static string _reformat( string str )
{
	std::stringstream check1(str);
	string dest, temp;

	
	while (dest == "" && getline(check1, dest, ' '))
	{
		if (dest.find_first_not_of(' ') == string::npos)
			dest = "";
		else
			dest.erase(0, dest.find_first_not_of(' '));
	}

	while (getline(check1, temp, ' '))
		if (temp.find_first_not_of(' ') != string::npos) {dest.append(' ' + temp);}
	return (dest);
}
int RPN::execute( string operation ) throw (GenericError)
{
	operation = _reformat(operation);
	if (!_valid_input(operation))
		throw (GenericError());

	for (string::iterator it = operation.begin(); it < operation.end(); it++)
	{
		if (*it == ' ')
			continue ;
		
		if (_is_operator(*it))
		{
			if (_operand.size() < 2)
				throw (MissingOperand());
			int op2 = _operand.top();
			_operand.pop();
			int op1 = _operand.top();
			_operand.pop();

			int res;
			switch (*it)
			{
			case '+':
				res = op1 + op2;
				break;
			case '-':
				res = op1 - op2;
				break;
			case '*':
				res = op1 * op2;
				break;
			case '/':
				if (op2 == 0)
				{
					if (op1 == 0)
						throw(UndefinedResult()); 
					throw(ZeroDivision());
				}
				res = op1 / op2;
				break;
			default:
				break ;
			}
			_operand.push(res);
		}
		else
		{
			_operand.push(*it - '0');
		}
	}
	if (_operand.size() != 1)
		throw (TooManyOperands());

	int result = _operand.top(); 
	_operand.pop();
	return result;
}

std::stack<int> RPN::_operand;