/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:38:26 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/07 23:43:57 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource( void );
	virtual void		learnMateria( AMateria* m ) = 0;
	virtual AMateria*	createMateria(std::string const & type) = 0;
};