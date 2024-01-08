/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:41:53 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/06 20:48:41 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	;
}
Brain::Brain( Brain & ref )
{
	*this = ref;
}
Brain::~Brain( void )
{
	return ;
}

Brain & Brain::operator=( Brain & rhs )
{
	for (int i = 0; i < Brain::NIDEAS; i++)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}