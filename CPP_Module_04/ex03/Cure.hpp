/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:45:54 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/07 23:40:42 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

class Cure : public AMateria {
private:
	Cure & operator=( Cure & );
	Cure( Cure & );
public:
	Cure( void );
	~Cure( void );
	void		use( ICharacter& target );
	AMateria	*clone( void ) const;
};