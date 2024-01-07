/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:57:22 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/07 23:41:41 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"
# include <string>

class AMateria;

class Character : public ICharacter
{
private:
	static const int	INV_SIZE = 4;
	AMateria 			*_materias[INV_SIZE];
	int					_nMaterias;
	std::string			_name;

	void	_printName( void ) const;
	Character( void );
public:
	std::string const & getName( void ) const;
	void	equip( AMateria* m );
	void	unequip( int idx );
	void	use( int idx, ICharacter& target ) const;
	Character( std::string name );
	Character( Character & ref );
	~Character( void );
	Character & operator=( Character & rhs );
};