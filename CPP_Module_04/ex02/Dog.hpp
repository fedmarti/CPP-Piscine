/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:19:15 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/05 13:10:48 by fedmarti         ###   ########.fr       */
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
	using Animal::makeSound;
	void makeSound( void ) const;
};