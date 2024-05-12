/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:18:53 by fedmarti          #+#    #+#             */
/*   Updated: 2024/05/12 02:31:15 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Span
{
public:

	void		addNumber( int );
	unsigned	shortestSpan();
	unsigned	longestSpan();
	Span( unsigned );
private:
	const unsigned _N;
	Span( void );
	~Span( void );
	Span( Span & );
	Span & operator=( Span & );
};