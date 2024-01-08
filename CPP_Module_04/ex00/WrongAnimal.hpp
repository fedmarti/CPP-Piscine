/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <fedmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:54:09 by fedmarti          #+#    #+#             */
/*   Updated: 2024/01/05 18:54:48 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class WrongAnimal {
public:
	WrongAnimal( void );
	WrongAnimal( WrongAnimal & );
	virtual ~WrongAnimal( void );
	WrongAnimal & operator=( WrongAnimal & );

	std::string		getType( void ) const;
	void	makeSound( void ) const; 
protected:
	std::string _type;
};