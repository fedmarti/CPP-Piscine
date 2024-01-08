/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:25:07 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/05 12:55:06 by fedmarti         ###   ########.fr       */
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

	void makeSound( void ) const;
};