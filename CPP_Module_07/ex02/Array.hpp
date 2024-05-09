/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:13:18 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/09 18:18:32 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <cstdlib>

template <typename T>
class Array {
private:
	long _size;
	T	*_array;
public:

	unsigned int	size( void ) const
	{
		return _size;
	};
	
	class IndexOutOfRange : public std::exception
	{
	public:
		const char *what( void ) const throw()
		{
			return "Index out of range";
		};
	};
	
	T	&operator []( long n ) throw (IndexOutOfRange)
	{
		if (n < 0 || n >= _size)
			throw (IndexOutOfRange());
		return (_array[n]);
	};
	
	Array<T>	&operator = ( Array<T> &rhs )
	{
		delete[] _array;
		_size = rhs.size();
		if (_size <= 0)
			return (*this);

		_array = new T[_size];
		for (long i = 0; i < _size; i++)
			_array[i] = rhs[i];
		return (*this);
	};
	
	Array( Array<T> &ref ) : _size(ref.size()), _array(NULL)
	{
		if (_size <= 0)
		return ;
	
		*this = ref;	
	};

	Array( void ) : _size(0), _array(NULL)
	{
		;
	};
	
	explicit Array( unsigned int size ) : _size(size) 
	{
		_array = new T[size];	
	};
	
	~Array( void )
	{
		delete []_array;
	};
};
