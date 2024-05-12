/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:18:53 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/12 20:38:00 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <vector>
#include <iostream>

class Span
{
public:

	Span( unsigned );
	Span( Span & );
	~Span( void );
	class FullSpan : public std::exception {
		const char	*what( void ) const throw();
	};
	class EmptySpan : public std::exception {
		const char	*what( void ) const throw();
	};

	void		addNumber( int ) throw (FullSpan);
	void		addRange( int, int ) throw (FullSpan);
	unsigned	shortestSpan() const throw (EmptySpan);
	unsigned	longestSpan() const throw (EmptySpan);
	int			operator[] ( int ) const;
	unsigned	getN( void ) const;
	unsigned	size( void ) const;
private:
	const unsigned _N;
	std::vector<int> _vector;
	Span( void );
	Span & operator=( Span & );
};

std::ostream & operator << ( std::ostream &output, Span &rhs );