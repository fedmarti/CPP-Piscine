/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:15:03 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/08 22:54:34 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _A_MATERIA_H_
# define _A_MATERIA_H_
# include <string>
# include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;
	AMateria & operator=( AMateria & ref );
	AMateria( AMateria & ref );
	AMateria( void );
public:
	AMateria( std::string const & type );
	virtual ~AMateria( void );
	std::string const &	getType( void ) const;
	virtual AMateria*	clone( void ) const = 0;
	virtual void		use( ICharacter& target );
};

#endif