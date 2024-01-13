/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:28:11 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/13 15:59:04 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

std::string const & Character::getName() const
{
	return (this->_name);
}

void	Character::_printName( void ) const
{
	std::cout << this->_name << ": ";
}

void	Character::equip( AMateria *m )
{
	this->_printName();
	if (!m)
	{
		std::cout << "Couldn't equip NULL materia" << std::endl;
		return ;
	}
	std::cout << "Equipped materia " << m->getType();
	if (this->_nMaterias >= Character::INV_SIZE)
	{
		std::cout << "... But the inventory was full...\nThe materia was destroyed..." << std::endl;
		delete m;
		return ;
	}
	std::cout << " in slot " << _nMaterias << std::endl;
	this->_materias[_nMaterias] = m;
	this->_nMaterias++;
}

void	Character::unequip( int idx )
{
	this->_printName();
	if (idx >= this->_nMaterias || idx < 0)
	{
		std::cout << "Tried to unequip a materia from slot " << idx << " but it was empty..." << std::endl;
		return ;
	}
	std::cout << "Unequipped materia " << this->_materias[idx]->getType() << " from slot " << idx << std::endl;
	delete this->_materias[idx];
	this->_materias[idx] = NULL;
	for (int i = idx; i < this->_nMaterias - 1; i++)
		this->_materias[i] = this->_materias[i + 1];
	this->_nMaterias--;
}

void	Character::use( int idx, ICharacter& target ) const
{
	this->_printName();
	if (idx >= this->_nMaterias || idx < 0)
	{
		std::cout << "Tried to use a materia from slot " << idx << " but it was empty..." << std::endl;
		return ;
	}
	this->_materias[idx]->use(target);
}

Character::Character( void ) : _nMaterias(0), _name("Default")
{
	for (int i = 0; i < Character::INV_SIZE; i++)
		this->_materias[i] = NULL;
}

Character::Character( Character & ref ) : _nMaterias(0)
{
	for (int i = 0; i < Character::INV_SIZE; i++)
		this->_materias[i] = NULL;
	*this = ref;
}

Character::Character( std::string name ) : _nMaterias(0), _name(name)
{
	for (int i = 0; i < Character::INV_SIZE; i++)
		this->_materias[i] = NULL;
}

Character::~Character( void )
{
	for (int i = 0; i < this->_nMaterias; i++)
		if (this->_materias[i]) {delete this->_materias[i];}
}

Character & Character::operator=( Character & rhs )
{
	this->_name = rhs._name;
	for (int i = 0; i < Character::INV_SIZE; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
		if (rhs._materias[i])
			this->_materias[i] = rhs._materias[i]->clone();
		else
			rhs._materias[i] = NULL;
	}
	this->_nMaterias = rhs._nMaterias;
	return (*this);
}