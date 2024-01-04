/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:20:03 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/05 00:27:29 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Animal {
public:
	Animal( void );
	Animal( Animal & );
	~Animal( void );
	Animal & operator=( Animal & );

	void makeSound( void ); 
protected:
	std::string _type;
};