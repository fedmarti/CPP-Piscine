/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:53:49 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/07 20:11:52 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
private:
	static const int MAX_MAT = 4;
	AMateria *_materias[MAX_MAT];
	MateriaSource & operator=( MateriaSource & );
	int	_learned;
public:
	MateriaSource( MateriaSource & );
	MateriaSource( void );
	~MateriaSource( void );
	void learnMateria( AMateria* );
	AMateria* createMateria( std::string const & type );
};