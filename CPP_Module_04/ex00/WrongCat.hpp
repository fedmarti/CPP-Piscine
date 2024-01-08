/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:55:59 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/05 18:56:30 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat( void );
	WrongCat( WrongCat & );
	~WrongCat( void );
	WrongCat & operator=( WrongCat & );

	void makeSound( void ) const;
};