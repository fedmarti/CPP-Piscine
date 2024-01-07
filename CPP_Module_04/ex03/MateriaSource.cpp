/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 20:05:56 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/08 00:00:34 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource & MateriaSource::operator=( MateriaSource & rhs )
{
	static_cast<void>(rhs);
	return (*this);
}


MateriaSource::MateriaSource( MateriaSource & ref )
{
	static_cast<void>(ref);;
}
MateriaSource::MateriaSource( void ) : _learned(0)  
{
	for (int i = 0; i < MateriaSource::MAX_MAT; i++)
		this->_materias[i] = NULL;;
}

MateriaSource::~MateriaSource( void )
{
	for (int i = 0; i < this->_learned; i++)
		delete this->_materias[i];
}
void MateriaSource::learnMateria( AMateria* m )
{
	if (this->_learned == MateriaSource::MAX_MAT)
	{
		if (m)
			delete m;
		return ;
	}
	this->_materias[this->_learned] = m;
	this->_learned++;
}
	
AMateria* MateriaSource::createMateria( std::string const & type )
{
	for (int i = 0; i < this->_learned; i++)
		if (type == this->_materias[i]->getType()) {return this->_materias[i]->clone();}
	return (NULL);
}