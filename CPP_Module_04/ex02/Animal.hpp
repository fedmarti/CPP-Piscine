/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:20:03 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/07 13:03:18 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "Brain.hpp"

class Animal {
public:
	Animal( void );
	Animal( Animal & );
	virtual ~Animal( void );
	Animal & operator=( Animal & );

	Brain			*getBrain( void ) const;
	std::string		getType( void ) const;
	virtual void	makeSound( void ) const = 0; 
protected:
	std::string _type;
	Brain 		*_brain;
};