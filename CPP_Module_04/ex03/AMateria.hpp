/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:15:03 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/07 23:53:48 by fedmarti         ###   ########.fr       */
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
public:
	AMateria( std::string const & type );
	virtual ~AMateria( void );
	std::string const &	getType( void ) const;
	virtual AMateria*	clone( void ) const = 0;
	virtual void		use( ICharacter& target );
};

#endif