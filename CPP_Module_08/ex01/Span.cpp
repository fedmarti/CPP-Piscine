/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:16:55 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/20 17:02:28 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span( void ) : _N(0), _vector()
{
	;
}

Span::Span( Span & ref ) : _N(ref._N), _vector(ref._vector)
{
	;
}

Span::~Span( void )
{
	;
}

Span & Span::operator=( Span & ref )
{
	(void)ref;
	return (*this);
}

void		Span::addNumber( int value ) throw (FullSpan)
{
	if (_vector.size() == _N)
		throw (FullSpan());

	_vector.insert(std::upper_bound(_vector.begin(), _vector.end(), value), value);
}

unsigned	Span::shortestSpan() const throw (EmptySpan)
{
	if (_vector.size() < 2)
		throw(EmptySpan());
	
	int shortest = _vector[1] - _vector[0];
	for (std::vector<int>::const_iterator i = _vector.begin(); i != _vector.end() - 1; i++)
	{
		shortest = std::min(shortest, *(i + 1) - *i);
	}
	return (shortest);
}

unsigned	Span::longestSpan() const throw(EmptySpan)
{
	if (_vector.size() < 2)
		throw(EmptySpan());

	return static_cast<unsigned>(_vector.back() - _vector.front());
}

void		Span::addRange( int min, int max ) throw (FullSpan)
{
	if (min > max)
	{
		int temp = max;
		max = min;
		min = temp;
	}
	std::vector<int>::iterator ub = std::upper_bound(_vector.begin(), _vector.end(), max);
	for (int i = 0; min + i <= max; i++)
	{
		if (_vector.size() == _vector.capacity())
			throw (FullSpan());
		_vector.insert(ub, min + i);
		ub++;
	}
}

/*void		addRange( int *start, int *end) throw (FullSpan)
{

}*/

Span::Span( unsigned size ): _N(size), _vector(0)
{
	_vector.reserve(size);
}
const char	*Span::FullSpan::what( void ) const throw()
{
	return "Full span";
}

const char	*Span::EmptySpan::what( void ) const throw()
{
	return "Empty span";
}

int			Span::operator[] (int index) const
{
	return (_vector[index]);
}

unsigned	Span::getN( void ) const
{
	return _N;
}

unsigned	Span::size( void ) const
{
	return (_vector.size());
}

std::ostream & operator << ( std::ostream &output, Span &rhs )
{
	output << "[ ";
	if (rhs.size())
	{
		for (unsigned i = 0; i < rhs.size(); i++)
			output << rhs[i] << " ";
	}
	else
	{
		output << "... ";
	}
	output << "]";
	return (output);
}