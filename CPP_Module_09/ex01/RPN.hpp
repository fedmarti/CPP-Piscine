/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 03:42:06 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/20 05:37:21 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <string>
#include <exception>
using std::string;

class RPN
{
public:

	class GenericError : public std::exception
	{
	public:
		virtual const char *what( void ) const throw ();
	};
	class MissingOperand : public GenericError
	{
	public:
		const char *what( void ) const throw ();
	};
	class ZeroDivision : public GenericError
	{
	public:
		const char *what( void ) const throw ();
	};
	class UndefinedResult : public GenericError
	{
	public:
		const char *what( void ) const throw ();
	};
	class TooManyOperands : public GenericError
	{
	public:
		const char *what( void ) const throw ();
	};

	static int execute( string operation ) throw (GenericError);
private:
	static std::stack<int> _operand;
	RPN( void );
	~RPN( void );
	RPN( RPN & );
	RPN & operator= ( RPN & rhs );
};