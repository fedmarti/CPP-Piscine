/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:19:15 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/11 21:50:11 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog( void );
	Dog( Dog & );
	~Dog( void );

	Dog & operator=( Dog & );
	void makeSound( void ) const;
	Brain	*getBrain( void ) const;
private:
	Brain	*_brain;
};