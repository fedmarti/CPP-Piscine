/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:25:07 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/11 22:03:19 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat( void );
	Cat( Cat & );
	~Cat( void );
	Cat & operator=( Cat & );

	void 	makeSound( void ) const;
	Brain	*getBrain( void ) const;
private:
	Brain	*_brain;
};