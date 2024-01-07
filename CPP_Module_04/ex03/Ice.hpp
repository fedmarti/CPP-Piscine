/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:18:34 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/07 23:45:02 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	Ice & operator=( Ice & rhs );
	Ice( Ice & );
public:
	Ice( void );
	~Ice( void );
	void		use( ICharacter& target );
	AMateria	*clone( void ) const;
};
